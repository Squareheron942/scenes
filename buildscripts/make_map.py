import os, sys, argparse, json

def to_map_cell(c): # input: 32 bit int, output 16 bit conversion (last 2 bits are v and h flip)
    if c == 0: return 0
    n = c & 0xffff
    flip_h = bool(c & 0x80000000)
    flip_v = bool(c & 0x40000000)
    if flip_h:
        n |= 0x400
    if flip_v:
        n |= 0x800
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
    map_out = ''
    map_changes = 0

    if os.stat('map_edit_times.json').st_size == 0:
        with open('map_edit_times.json', 'w') as times:
            json.dump(times_dict, times)
    with open('map_edit_times.json', 'r') as times:
        times_dict = json.load(times)


        # with open(os.path.join(build_dir, 'pk_map_weather_tables.inc'), 'w') as map_list:

        map_out += '#ifndef PK_MAP_WEATHER_TABLES_H\n'
        map_out += '#define PK_MAP_WEATHER_TABLES_H\n'
        map_out += '\n'
        map_out += 'namespace pk::weather {\n'
        map_out += '    const unsigned char map_tables[][6] = {\n'

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
                flags = get_prop_val(props, 'Flags')
                if not id in times_dict:
                    times_dict[get_prop_val(props, 'ID')] = 0
                if not id + '_LAYOUT' in times_dict:
                    times_dict[id + '_LAYOUT'] = 0
                
                output_header_path = os.path.join(build_dir, "pk_map_items_" + id.split('MAP_')[1].lower() + '.h')

                # removes any illegal background maps
                if not map['height'] % 32 == 0: 
                    print("Invalid map height: " + map['height'] + " - 32")
                    continue
                if not map['width'] % 32 == 0: 
                    print("Invalid map width: " + map['width'] + " - 32")
                    continue

                map_out += '        {' + (', '.join(str(wodds[c]) for c in wodds))

                for i in wodds: weather_odds_total += wodds[i]

                map_out += '}, // ' + get_prop_val(props, 'Name') + '\n'
                num_maps += 1
                # compare last modified time to previous time script run, recreate header if it was
                if not (times_dict[id] != os.stat(os.path.join(map_dir, dir, 'layout.json')).st_mtime or not os.path.exists(os.path.join(build_dir, 'pk_map_items_' + id.split('MAP_')[1].lower() + '.h'))): continue
                map_changes += 1
                with open(output_header_path, 'w') as output_source:    
                    output_source.write('#ifndef ' + id + '_H' + '\n')
                    output_source.write('#define ' + id + '_H' + '\n\n')
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
                    output_source.write('   const pk::maps::types map_type = pk::maps::types::' + get_prop_val(props, 'Map Type') + ';\n')
                    output_source.write('   const bn::string_view id("' + id + '");\n')
                    output_source.write('   const bn::string_view name("' + get_prop_val(props, 'Name') + '");\n')
                    output_source.write('   const bn::music_item music = bn::music_items::' + get_prop_val(props, 'Music').lower() + ';\n')
                    output_source.write('   const bn::size map_size(' + str(map['width']) + ', ' + str(map['height']) + ');\n')
                    output_source.write('   const bool allow_cycling = ' + str(flags['allow_cycling']).lower() + ';\n')
                    output_source.write('   const bool allow_escaping = ' + str(flags['allow_escaping']).lower() + ';\n')
                    output_source.write('   const bool requires_flash = ' + str(flags['require_flash']).lower() + ';\n')
                    output_source.write('   const bool show_map_name = ' + str(flags['show_map_name']).lower() + ';\n')
                    output_source.write('   const bool do_seasons = ' + str(flags['do_seasons']).lower() + ';\n')
                    output_source.write('   const bool do_weather = ' + str(flags['do_weather']).lower() + ';\n')
                    output_source.write('   const pk::weather::types default_weather = pk::weather::types::' + get_prop_val(props, 'Default Weather') + ';\n')
                    output_source.write('   const pk::seasons::types default_season = pk::seasons::types::' + get_prop_val(props, 'Default Season') + ';\n')
                    output_source.write('\n')
                    for i in range(len(map['layers'])):
                        output_source.write(f'   const unsigned short layout{i}[] = {{')
                        output_source.write((','.join(str(to_map_cell(c)) for c in to_right_order(map['layers'][i]['data'], map['width'], map['height']))))
                        output_source.write('};\n')
                    output_source.write('\n')
                    output_source.write('}\n')
                    output_source.write('#endif')

                    output_source.close()
                    print('    ' + dir + ' item header written in '+ str(output_header_path) + ' (data size: ' + str(os.stat(output_header_path).st_size) + ' bytes)')
                    total_size += os.stat(output_header_path).st_size
                times_dict[id] = os.stat(os.path.join(map_dir, dir, 'layout.json')).st_mtime
        map_out += '    };\n'
        map_out += '    const uint16_t map_tables_length = ' + str(num_maps) + ';\n'
        map_out += '}\n'
        map_out += '\n'
        map_out += '#endif'

        times.close()

        if map_changes: 
            with open(os.path.join(build_dir, 'pk_map_weather_tables.inc'), 'w') as map_list:
                map_list.write(map_out)
                map_list.close()

        with open('map_edit_times.json', 'w') as times:
            json.dump(times_dict, times)

    if total_size: print('    Processed data size: ' + str(total_size) + ' bytes')
    

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Map utility script')
    parser.add_argument('--build', required=True, help='build folder path')
    args = parser.parse_args()
    process(args.build)