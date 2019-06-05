#ifndef MONSTER_PARSE_H
#define MONSTER_PARSE_H

#include "monster.h"
#include "monster_builder.h"

#include <json/json.h>

namespace DnD {

Monster parse_monster(const Json::Value& root, const MonsterBuilder& b);

} // end namespace DnD

#endif