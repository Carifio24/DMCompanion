#ifndef FILTER_H
#define FILTER_H

#include "Enumerations.h"

bool usableByClass(const Spell& spell, const CasterClass& caster);

bool usableBySubclass(const Spell& spell, const Subclass& sub);

#endif
