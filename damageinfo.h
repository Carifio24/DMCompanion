#ifndef DAMAGEINFO_H
#define DAMAGEINFO_H

#include "Enumerations.h"

struct DamageInfo {
    DamageType damage_type;
    MagicType magic_type;
    std::string text;
};

#endif // DAMAGEINFO_H

