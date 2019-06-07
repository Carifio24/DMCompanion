#ifndef ENUMMAPS_H
#define ENUMMAPS_H

#include <string>
#include <map>

#include "enumerations.h"

namespace DnD {

extern const std::map<CreatureType,std::string> creatureTypeNames;

extern const std::map<DamageType,std::string> damageTypeNames;

extern const size_t N_CREATURE_TYPES;

extern const size_t N_DAMAGE_TYPES;

} // end namespace DnD

#endif // ENUMMAPS_H

