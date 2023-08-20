import os, sys, argparse, json

def process(build_dir):
    try:
        os.mkdir(build_dir)
    except:
        pass

    map_dir = os.path.join('data', 'maps')
    total_size = 0
    times_dict = {}

    if os.stat('scene_edit_times.json').st_size == 0:
        with open('scene_edit_times.json', 'w') as times:
            json.dump(times_dict, times)
    with open('map_edit_times.json', 'r') as times:
        times_dict = json.load(times)
    

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Scene list compiling script')
    parser.add_argument('--build', required=True, help='Build folder path')
    args = parser.parse_args()
    process(args.build)