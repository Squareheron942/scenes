import os, sys, argparse, json

def process(build_dir):
    map_dir = os.path.join('data', 'maps')
    total_size = 0
    times_dict = {}

    if os.stat('map_edit_times.json').st_size == 0:
        with open('map_edit_times.json', 'w') as times:
            json.dump(times_dict, times)
    with open('map_edit_times.json', 'r') as times:
        times_dict = json.load(times)

        with open(os.path.join(build_dir, 'pk_map_weather_tables.h'), 'w') as map_list:

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
                    map = json.load(open(os.path.join(map_dir, dir, 'map.json')))
                    if not map['id'] in times_dict:
                        times_dict[map['id']] = 0
                    if not map['id'] + '_LAYOUT' in times_dict:
                        times_dict[map['id'] + '_LAYOUT'] = 0
                    
                    output_header_path = os.path.join(build_dir, "pk_map_items_" + map['id'].split('MAP_')[1].lower() + '.h')
                    output_source_path = os.path.join(build_dir, "pk_map_items_" + map['id'].split('MAP_')[1].lower() + '.cpp')

                    # removes any illegal background maps
                    if (map['dimensions']['height'] % 32 == 0 and map['dimensions']['width'] % 32 == 0): 
                        map_list.write('        {' + (', '.join(str(map['weather_odds'][c]) for c in map['weather_odds'])))

                        for i in map['weather_odds']: weather_odds_total += map['weather_odds'][i]

                        map_list.write('}, // ' + map['name'] + '\n')
                        num_maps += 1
                        # compare last modified time to previous time script run, recreate header if it was
                        if (times_dict[map['id']] != os.stat(os.path.join(map_dir, dir, 'map.json')).st_mtime or times_dict[map['id'] + '_LAYOUT'] != os.stat(os.path.join(map_dir, dir, 'layout.bin')).st_mtime or not os.path.exists(os.path.join(build_dir, 'pk_map_items_' + map['id'].split('MAP_')[1].lower() + '.h'))):
                            with open(os.path.join(map_dir, dir, 'layout.bin'), 'rb') as layout:
                                with open(output_header_path, 'w') as output_header:
                                    output_header.write('#ifndef ' + map['id'] + '_H' + '\n')
                                    output_header.write('#define ' + map['id'] + '_H' + '\n')
                                    output_header.write('\n')
                                    output_header.write('#include "bn_music_items.h"\n')
                                    output_header.write('#include "bn_regular_bg_map_item.h"\n')
                                    output_header.write('#include "bn_regular_bg_item.h"\n')
                                    output_header.write('#include "bn_size.h"\n')
                                    output_header.write('#include "bn_string_view.h"\n')
                                    output_header.write('#include "pk_maps.h"\n')
                                    output_header.write('#include "pk_weather.h"\n')
                                    output_header.write('#include "pk_seasons.h"\n')
                                    output_header.write('\n')
                                    output_header.write('namespace pk::maps::' + map['id'].split('MAP_')[1] + ' {\n')
                                    output_header.write('\n')
                                    output_header.write('   extern const uint8_t map_type;\n')
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
                                    output_header.write('   extern const uint8_t default_weather;\n')
                                    output_header.write('   extern const uint8_t default_season;\n')
                                    output_header.write('   extern const uint16_t layout[];\n')
                                    output_header.write('}\n')
                                    output_header.write('#endif')

                                    output_header.close()
                                with open(output_source_path, 'w') as output_source:
                                    output_source.write('#include "pk_map_items_' + map['id'].split('MAP_')[1].lower() + '.h"\n')
                                    output_source.write('#include "bn_music_items.h"\n')
                                    output_source.write('#include "bn_regular_bg_map_item.h"\n')
                                    output_source.write('#include "bn_regular_bg_item.h"\n')
                                    output_source.write('#include "bn_size.h"\n')
                                    output_source.write('#include "bn_string_view.h"\n')
                                    output_source.write('#include "pk_maps.h"\n')
                                    output_source.write('#include "pk_weather.h"\n')
                                    output_source.write('#include "pk_seasons.h"\n')
                                    output_source.write('\n')
                                    output_source.write('namespace pk::maps::' + map['id'].split('MAP_')[1] + ' {\n')
                                    output_source.write('\n')
                                    output_source.write('   const uint8_t map_type = pk::maps::types::' + map['map_type'] + ';\n')
                                    output_source.write('   const bn::string_view id("' + map['id'] + '");\n')
                                    output_source.write('   const bn::string_view name("' + map['name'] + '");\n')
                                    output_source.write('   const bn::music_item music = bn::music_items::' + map['music'].lower() + ';\n')
                                    output_source.write('   const bn::size map_size(' + str(map['dimensions']['width']) + ', ' + str(map['dimensions']['height']) + ');\n')
                                    output_source.write('   const bool allow_cycling = ' + str(map['allow_cycling']).lower() + ';\n')
                                    output_source.write('   const bool allow_escaping = ' + str(map['allow_escaping']).lower() + ';\n')
                                    output_source.write('   const bool requires_flash = ' + str(map['require_flash']).lower() + ';\n')
                                    output_source.write('   const bool show_map_name = ' + str(map['show_map_name']).lower() + ';\n')
                                    output_source.write('   const bool do_seasons = ' + str(map['do_seasons']).lower() + ';\n')
                                    output_source.write('   const bool do_weather = ' + str(map['do_weather']).lower() + ';\n')
                                    output_source.write('   const uint8_t default_weather = pk::weather::' + map['default_weather'] + ';\n')
                                    output_source.write('   const uint8_t default_season = pk::seasons::' + map['default_season'] + ';\n')
                                    output_source.write('\n')
                                    output_source.write('   const uint16_t layout[] = {')
                                    output_source.write((','.join(str(c) for c in layout.read(map['dimensions']['height'] * map['dimensions']['height']))))
                                    output_source.write('};\n')
                                    output_source.write('\n')
                                    output_source.write('}\n')

                                    output_source.close()

    #                                 uint16_t layout[] = {
    #       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    #    }

                                    print('    ' + dir + ' item header written in '+ str(output_header_path) + ' (data size: ' + str(os.stat(output_header_path).st_size) + ' bytes)')
                                    total_size += os.stat(output_header_path).st_size
                        times_dict[map['id']] = os.stat(os.path.join(map_dir, dir, 'map.json')).st_mtime
                        times_dict[map['id'] + '_LAYOUT'] = os.stat(os.path.join(map_dir, dir, 'layout.bin')).st_mtime
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
    parser = argparse.ArgumentParser(description='External tool example.')
    parser.add_argument('--build', required=True, help='build folder path')
    args = parser.parse_args()
    process(args.build)