import os, sys, argparse, json

def process(build_dir):
    try:
        os.mkdir(build_dir)
    except:
        pass

    total_size = 0
    size_diff = 0
    times_dict = {}

    if os.stat('scene_edit_times.json').st_size == 0:
        with open('scene_edit_times.json', 'w') as times:
            json.dump(times_dict, times)
    with open('map_edit_times.json', 'r') as times:
        times_dict = json.load(times)

        with open(os.path.join(build_dir, 'pk_scenes_list.inc'), 'w') as output:
            output.write('#ifndef PK_SCENE_LIST_H\n')
            output.write('#define PK_SCENE_LIST_H\n\n')

            for file in os.listdir(os.path.join('src', 'scenes')):
                if os.path.isfile(os.path.join('src', 'scenes', file)): 
                    output.write('#include "' + os.path.basename(file).split('.cpp')[0] + '.h"\n')
                    try:
                        if (times_dict[os.path.basename(file)] != os.stat(os.path.join('src', 'scenes', file)).st_mtime): 
                            print('   ' + os.path.basename(file))
                            size_diff += 1
                    except:
                        print('   ' + os.path.basename(file))
                        size_diff += 1
                        pass
                    total_size += 1
                    times_dict[os.path.basename(file)] = os.stat(os.path.join('src', 'scenes', file)).st_mtime
            output.write('\nconst int num_scn = ' + str(total_size) + ';\n')
            output.write('\n#endif')
            if size_diff > 0:
                print('Compiled scenes list written to ' + os.path.join(build_dir, 'pk_scenes_list.inc'))
    with open('map_edit_times.json', 'w') as times:
        json.dump(times_dict, times)
    

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Scene list compiling script')
    parser.add_argument('--build', required=True, help='Build folder path')
    args = parser.parse_args()
    process(args.build)