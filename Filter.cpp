#include "Classes.h"

bool usableByClass(const Spell& spell, const CasterClass& caster) {
	for (const CasterClass& cc : spell.classes) {
		if (cc == caster) {
			return true;
		}
	}
	return false;
}

bool usableBySubclass(const Spell& spell, const Subclass& sub) {
	for (const Subclass& sc : spell.subclasses) {
		if (sc == sub) {
			return true;
		}
	}
	return false;
}