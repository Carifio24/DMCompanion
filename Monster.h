#ifndef MONSTER_H
#define MONSTER_H

#include "Enumerations.h"
#include "ability.h"
#include "action.h"
#include "alignment.h"
#include "fraction.h"
#include "damageinfo.h"

#include "Creature.h"

#include <utility>

class Monster : public Creature {

    public:


    private:
        const int _history;
        friend class MonsterBuilder;

};

#endif // MONSTER_H
