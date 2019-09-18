import json

monster_filename = "Monsters.json"
output_filename = "Monsters_by_Type.txt"

with open(monster_filename, 'r') as f:
    json_str = f.read()

json = json.loads(json_str)

by_type = {}
for doc in json:

    # Skip the license
    if "license" in doc.keys():
        continue

    t = doc["type"]
    name = doc["name"]

    if t in by_type.keys():
        by_type[t].append(name)
    else:
        by_type[t] = [ name ]

with open(output_filename, 'w') as f:
    for t in by_type.keys():
        f.write("Type: %s\n" % t)
        for name in by_type[t]:
            f.write("\t--%s\n" % name)