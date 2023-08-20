import os, sys, argparse, json

def to_map_cell(c): # input: 32 bit int, output 16 bit conversion (last 2 bits are v and h flip)
    n = c & 0xffff
    flip_h = bool(c & 0x80000000)
    flip_v = bool(c & 0x40000000)
    if flip_h:
        n |= 0x8000
    if flip_v:
        n |= 0x4000
    return n - 1

def to_right_order(map, width, height):
    out_map = [1] * (width * height)
    for i in range(0, width * height):
        x = i % width
        y = i // width
        sbb = (y//32)*(width//32) + (x//32)
        out_map[sbb*1024 + (y%32)*32 + x%32] = map[i]
    return out_map

def get_prop_val(properties, name):
    for prop in properties:
        if prop['name'] == name:
            return prop['value']
    return "not found"

def process(build_dir):
    try:
        os.mkdir(build_dir)
    except:
        pass
    map_dir = os.path.join('data', 'maps')
    total_size = 0
    times_dict = {}

    if os.stat('map_edit_times.json').st_size == 0:
        with open('map_edit_times.json', 'w') as times:
            json.dump(times_dict, times)
    with open('map_edit_times.json', 'r') as times:
        times_dict = json.load(times)


        with open(os.path.join(build_dir, 'pk_map_weather_tables.inc'), 'w') as map_list:

            map_list.write('#ifndef PK_MAP_WEATHER_TABLES_H\n')
            map_list.write('#define PK_MAP_WEATHER_TABLES_H\n')
            map_list.write('\n')
            map_list.write('#include "bn_core.h"')
            map_list.write('\n')
            map_list.write('namespace pk::weather {\n')
            map_list.write('    const uint8_t map_tables[][6] = {\n')

            num_maps = 0

            for subdir, dirs, files in os.walk(map_dir):
                weather_odds_total = 0
                for dir in dirs:
                    if dir == 'build': return
                    
                    
                    try: map = json.load(open(os.path.join(map_dir, dir, 'layout.json')))
                    except: continue
                    
                    
                    props = map['properties']
                    wodds = get_prop_val(props, 'Weather Odds')
                    id = get_prop_val(props, 'ID')
                    print(id)
                    flags = get_prop_val(props, 'Flags')
                    if not id in times_dict:
                        times_dict[get_prop_val(props, 'ID')] = 0
                    if not id + '_LAYOUT' in times_dict:
                        times_dict[id + '_LAYOUT'] = 0
                    
                    output_header_path = os.path.join(build_dir, "pk_map_items_" + id.split('MAP_')[1].lower() + '.h')
                    output_source_path = os.path.join(build_dir, "pk_map_items_" + id.split('MAP_')[1].lower() + '.cpp')

                    # removes any illegal background maps
                    if not (map['height'] % 32 == 0 and map['width'] % 32 == 0): continue

                    map_list.write('        {' + (', '.join(str(wodds[c]) for c in wodds)))

                    for i in wodds: weather_odds_total += wodds[i]

                    map_list.write('}, // ' + get_prop_val(props, 'Name') + '\n')
                    num_maps += 1
                    # compare last modified time to previous time script run, recreate header if it was
                    if not (times_dict[id] != os.stat(os.path.join(map_dir, dir, 'layout.json')).st_mtime or not os.path.exists(os.path.join(build_dir, 'pk_map_items_' + id.split('MAP_')[1].lower() + '.h'))): continue
                    with open(output_header_path, 'w') as output_header:
                        output_header.write('#ifndef ' + id + '_H' + '\n')
                        output_header.write('#define ' + id + '_H' + '\n')
                        output_header.write('\n')
                        output_header.write('#include "bn_music_items.h"\n')
                        output_header.write('#include "bn_regular_bg_map_item.h"\n')
                        output_header.write('#include "bn_regular_bg_item.h"\n')
                        output_header.write('#include "bn_size.h"\n')
                        output_header.write('#include "bn_string_view.h"\n')
                        output_header.write('#include "pk_maps.h"\n')
                        output_header.write('#include "pk_weather_types.h"\n')
                        output_header.write('#include "pk_seasons_types.h"\n')
                        output_header.write('\n')
                        output_header.write('namespace pk::maps::' + id.split('MAP_')[1] + ' {\n')
                        output_header.write('\n')
                        output_header.write('   extern const pk::maps::types map_type;\n')
                        output_header.write('   extern const bn::string_view id;\n')
                        output_header.write('   extern const bn::string_view name;\n')
                        output_header.write('   extern const bn::music_item music;\n')
                        output_header.write('   extern const bn::size map_size;\n')
                        output_header.write('   extern const bool allow_cycling;\n')
                        output_header.write('   extern const bool allow_escaping;\n')
                        output_header.write('   extern const bool requires_flash;\n')
                        output_header.write('   extern const bool show_map_name;\n')
                        output_header.write('   extern const bool do_seasons;\n')
                        output_header.write('   extern const bool do_weather;\n')
                        output_header.write('   extern const pk::weather::types default_weather;\n')
                        output_header.write('   extern const pk::seasons::types default_season;\n')
                        output_header.write('   extern const unsigned short layout[];\n')
                        output_header.write('}\n')
                        output_header.write('#endif')

                        output_header.close()
                    with open(output_source_path, 'w') as output_source:
                        output_source.write('#include "pk_map_items_' + id.split('MAP_')[1].lower() + '.h"\n')
                        output_source.write('#include "bn_music_items.h"\n')
                        output_source.write('#include "bn_regular_bg_map_item.h"\n')
                        output_source.write('#include "bn_regular_bg_item.h"\n')
                        output_source.write('#include "bn_size.h"\n')
                        output_source.write('#include "bn_string_view.h"\n')
                        output_source.write('#include "pk_maps.h"\n')
                        output_source.write('#include "pk_weather_types.h"\n')
                        output_source.write('#include "pk_seasons_types.h"\n')
                        output_source.write('\n')
                        output_source.write('namespace pk::maps::' + id.split('MAP_')[1] + ' {\n')
                        output_source.write('\n')
                        output_source.write('   extern const pk::maps::types map_type = pk::maps::types::' + get_prop_val(props, 'Map Type') + ';\n')
                        output_source.write('   extern const bn::string_view id("' + id + '");\n')
                        output_source.write('   extern const bn::string_view name("' + get_prop_val(props, 'Name') + '");\n')
                        output_source.write('   extern const bn::music_item music = bn::music_items::' + get_prop_val(props, 'Music').lower() + ';\n')
                        output_source.write('   extern const bn::size map_size(' + str(map['width']) + ', ' + str(map['height']) + ');\n')
                        output_source.write('   extern const bool allow_cycling = ' + str(flags['allow_cycling']).lower() + ';\n')
                        output_source.write('   extern const bool allow_escaping = ' + str(flags['allow_escaping']).lower() + ';\n')
                        output_source.write('   extern const bool requires_flash = ' + str(flags['require_flash']).lower() + ';\n')
                        output_source.write('   extern const bool show_map_name = ' + str(flags['show_map_name']).lower() + ';\n')
                        output_source.write('   extern const bool do_seasons = ' + str(flags['do_seasons']).lower() + ';\n')
                        output_source.write('   extern const bool do_weather = ' + str(flags['do_weather']).lower() + ';\n')
                        output_source.write('   extern const pk::weather::types default_weather = pk::weather::types::' + get_prop_val(props, 'Default Weather') + ';\n')
                        output_source.write('   extern const pk::seasons::types default_season = pk::seasons::types::' + get_prop_val(props, 'Default Season') + ';\n')
                        output_source.write('\n')
                        output_source.write('   extern const unsigned short layout[] = {0')
                        # return
                        # print(to_right_order(map['layers'][0]['data'], map['width'], map['height']))

                        output_source.write((','.join(str(to_map_cell(c)) for c in to_right_order(map['layers'][0]['data'], map['width'], map['height']))))
                        output_source.write('};\n')
                        output_source.write('\n')
                        output_source.write('}\n')

                        output_source.close()

#                                 uint16_t layout[] = {
#       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#    }

                        print('    ' + dir + ' item header written in '+ str(output_header_path) + ' (data size: ' + str(os.stat(output_header_path).st_size) + ' bytes)')
                        total_size += os.stat(output_header_path).st_size
                    times_dict[id] = os.stat(os.path.join(map_dir, dir, 'layout.json')).st_mtime
            map_list.write('    };\n')
            map_list.write('    const uint16_t map_tables_length = ' + str(num_maps) + ';\n')
            map_list.write('}\n')
            map_list.write('\n')
            map_list.write('#endif')
            
            map_list.close()
            times.close()

            with open('map_edit_times.json', 'w') as times:
                json.dump(times_dict, times)

    if total_size > 0: print('    Processed data size: ' + str(total_size) + ' bytes')
    

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Map utility script')
    parser.add_argument('--build', required=True, help='build folder path')
    args = parser.parse_args()
    process(args.build)