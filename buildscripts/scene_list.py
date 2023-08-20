import os, sys, argparse, json

def process(build_dir):
    try:
        os.mkdir(build_dir)
    except:
        pass

    total_size = 0
    size_diff = not os.path.exists('data/build/pk_scenes_list.inc')
    names_dict = []
    out = ''

    if os.stat('scene_names.json').st_size == 0:
        with open('scene_names.json', 'w') as names:
            json.dump(names_dict, names)
    with open('scene_names.json', 'r') as names:
        names_dict = json.load(names)
        out += '#ifndef PK_SCENE_LIST_H\n'+'#define PK_SCENE_LIST_H\n\n'

        

        for file in os.listdir(os.path.join('src', 'scenes')):
            if os.path.isfile(os.path.join('src', 'scenes', file)): 
                out+='#include "' + os.path.basename(file).split('.cpp')[0] + '.h"\n'
                
                if not os.path.basename(file) in names_dict: 
                    print('   ' + os.path.basename(file))
                    size_diff += 1
                try:
                    names_dict[total_size] = os.path.basename(file)
                except:
                    names_dict.append(os.path.basename(file))
                total_size += 1
        out+='\nconst int num_scn = ' + str(total_size) + ';\n'
        out+='\n#endif'
        if bool(size_diff):
            print('Compiled scenes list written to ' + os.path.join(build_dir, 'pk_scenes_list.inc'))
            with open(os.path.join(build_dir, 'pk_scenes_list.inc'), 'w') as output:
                output.write(out)
            with open('scene_names.json', 'w') as names:
                json.dump(names_dict, names)
    

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Scene list compiling script')
    parser.add_argument('--build', required=True, help='Build folder path')
    args = parser.parse_args()
    process(args.build)