#include "action.h"
#include "jstring.h"
#include "Parse.h"

// JSON constructor
Action::Action(const Json::Value& root) {
    name = root["name"].asString();
    desc = root["desc"].asString();
    attackBonus = int_if_member(root, "attack_bonus");
    damageBonus = int_if_member(root, "damage_bonus");

    if (root.isMember("damage_dice")) {
        std::vector<std::string> dd_str = jstring::split(root["damage_dice"].asString(), " + ");
        for (const std::string& s : dd_str) {
            damageDice.push_back(dice_from_string(s));
        }
    }
}
