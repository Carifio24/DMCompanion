import json

def chars_to_school(ch):
	if ch == "A":
		return "Abjuration"
	if ch == "C":
		return "Conjuration"
	if ch == "D":
		return "Divination"
	if ch == "EV":
		return "Evocation"
	if ch == "I":
		return "Illusion"
	if ch == "N":
		return "Necromancy"
	if ch == "T":
		return "Transmutation"

# Get the XGE spell data JSON
fname = "XGESpells.json"
f = open(fname)
xgedata = f.read()
f.close()

# The container for the converted data
converted_data = {"spell" : []}

# Read through the documents and convert each one to the new list
xgedata = json.load(xgedata)
spells = xgedata["spell"]
for s in spells:
	snew = {}
	snew["data"] = s["data"]
	snew["level"] = s["level"]
	snew["school"] = {"name" : chars_to_school(s["school"])}
	snew["casting_time"] = s["time"]
	snew["range"] = s["range"]
	duration_text = s["duration"]
	if duration_text.startswith("Concentration"):
		snew["duration"] = True
		duration_text = duration_text[len("Concentration, "):]
		duration_text[0] = duration_text[0].upper()
	else:
		snew["duration"] = False
	snew["duration"] = duration_text
	classes = s["classes"]
	classes = classes.strip()
	classes = classes.replace("Rogue (Arcane Tricksster),", "")
	classes = classes.replace("Fighter (Eldritch Knight),", "")
	classes = classes.split(",")
	snew["classes"] = [ {"name" : cname} for cname in classes ]
	components_text = s["components"]
	components = components_text.strip().split(",")
	materials = ""
	for i,comp in enumerate(components):
		if comp.startswith("M"):
			components[i] = "M"
			materials = comp[2:-1]
	snew["components"] = [x for x in components]
	if materials:
		snew["material"] = materials
	description_text = s["text"][:-2] # Cut out the ending null and "This spell can be found..."
	description_text = [w for w in description_text if w is not None]
	description = []
	higher_level = ""
	for t in description_text:
		if t.startswith("At Higher Levels: "):
			higher_level = t[len("At Higher Levels: "):]
		else:
			description.append(t)
	if s["ritual"] = "YES":
		snew["ritual"] = "yes"