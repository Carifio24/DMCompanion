import os
import json
from fnmatch import fnmatch

json_file = "Monsters.json"
images_dir = "monster_images"
output_file = "Monsters_Images.json"

with open(json_file, 'r') as f, open(output_file, 'w') as g:
    data = json.load(f)
    data_out = data

    for i in range(len(data)):
        m = data[i]
        if "license" in m.keys():
            continue
        name = m["name"]
        name = name.replace(" ", "_").replace("/","")
        wc = '%s.*' % name

        found = False
        for fname in os.listdir(images_dir):
            if fnmatch(fname, wc):
                data_out[i]["image_file"] = os.path.join(images_dir, fname)
                found = True
                break
        if not found:
            print(name)
        

    json.dump(data_out, g, indent=4)