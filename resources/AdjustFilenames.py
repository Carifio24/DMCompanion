import json

def snake_case_format(type_name):
    type_name = type_name.lower()
    type_name = type_name.replace(" ", "_")
    return type_name

# The file to use
monster_filename = "monsters/Monsters.json"

# Read and parse the JSON
with open(monster_filename, 'r') as f:
    json_str = f.read()
js = json.loads(json_str)

# Iterate over the monsters
for doc in js:

    # Skip the license
    if "license" in doc.keys() or "image_file" not in doc.keys():
        continue
    
    # Get the type, and format_it_like_this
    t = doc["type"]
    t = snake_case_format(t)

    # Get the old filename and split it
    # Should have the form "monster_images/Name.ext"
    old_file = doc["image_file"]
    old_pieces = old_file.split("/")
    assert(len(old_pieces) == 2)

    # The new file name is "monster_images/type/Name.ext"
    new_file = "%s/%s/%s" % (old_pieces[0], t, old_pieces[1])
    doc["image_file"] = new_file

# Write the updated JSON entries to the output file (same as the original)
with open(monster_filename,'w') as f:
    f.write(json.dumps(js, sort_keys=False, indent=4))