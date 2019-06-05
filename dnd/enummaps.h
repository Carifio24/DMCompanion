#ifndef ENUMMAPS_H
#define ENUMMAPS_H

#include <string>
#include <map>

#include "enumerations.h"

extern const std::map<School,std::string> schoolNames;

extern const std::map<CasterClass,std::string> casterNames;

extern const std::map<Subclass,std::string> subclassNames;

extern const std::map<Sourcebook,std::string> sourcebookNames;

extern const std::map<Sourcebook,std::string> sourcebookCodes;

extern const std::map<Size,std::string> sizeNames;

extern const std::map<CreatureType,std::string> creatureTypeNames;

extern const std::map<SpeedType,std::string> speedTypeNames;

extern const std::map<DamageType,std::string> damageTypeNames;

extern const std::map<Condition,std::string> conditionNames;

extern const std::map<Sense,std::string> senseNames;

extern const size_t N_SCHOOLS;

extern const size_t N_CASTERS;

extern const size_t N_SUBCLASSES;

extern const size_t N_SOURCES;

extern const size_t N_SIZES;

extern const size_t N_CREATURE_TYPES;

extern const size_t N_SPEED_TYPES;

extern const size_t N_DAMAGE_TYPES;

extern const size_t N_CONDITIONS;

extern const size_t N_SENSES;

#endif // ENUMMAPS_H

