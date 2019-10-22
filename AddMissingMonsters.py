import os
import json
import fnmatch

def spaces_to_underscores(name):
    return name.replace(" ", "_")

missing_monsters_file = "MissingMonsterImages.txt"
monster_types = [
    "aberration",
    "beast",
    "celestial",
    "construct",
    "dragon",
    "elemental",
    "fey",
    "fiend",
    "giant",
    "humanoid",
    "monstrosity",
    "ooze",
    "plant",
    "swarm_of_tiny_beasts",
    "undead"
]
missing_monsters = []

with open(missing_monsters_file, 'r') as f:
    for x in f:
        missing_monsters.append(x)

json_file = "resources/monsters/Monsters.json"
with open(json_file, 'r') as f:
    monsters_json = json.loads(f.read())

for (idx, mon) in enumerate(monsters_json):

    if "license" in mon.keys() or "image_file" in mon.keys():
        continue

    name = mon["name"]
    t = mon["type"].lower()
    t = spaces_to_underscores(t)
    type_dir = "resources/monsters/monster_images/%s" % t
    type_dir_short = "monster_images/%s" % t
    type_imgs = os.listdir(type_dir)
    name_us = spaces_to_underscores(name)
    rgx = "%s*" % name_us
    # print(name)
    # print(type_dir)
    # print(type_imgs)
    # print(rgx)
    flist = fnmatch.filter(type_imgs, rgx)
    if len(flist) == 1:
        print("Added image file for %s" % name)
        mon["image_file"] = os.path.join(type_dir_short, flist[0])
    monsters_json[idx] = mon

output_file = "resources/monsters/Monsters_ImagesAdded.json"
with open(output_file, 'w') as g:
    json.dump(monsters_json, g, sort_keys=False, indent=4)