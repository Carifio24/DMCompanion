#ifndef KEYS_H
#define KEYS_H

#include <string>

// Keys for JSON parsing
namespace keys {
    inline const std::string name_k = "name";
    inline const std::string page_k = "page";
    inline const std::string range_k = "range";
    inline const std::string casting_time_k = "casting_time";
    inline const std::string level_k = "level";
    inline const std::string concentration_k = "concentration";
    inline const std::string ritual_k = "ritual";
    inline const std::string description_k = "desc";
    inline const std::string higher_level_k = "higher_level";
    inline const std::string components_k = "components";
    inline const std::string material_k = "material";
    inline const std::string school_k = "school";
    inline const std::string classes_k = "classes";
    inline const std::string subclasses_k = "subclasses";
    inline const std::string duration_k = "duration";
    inline const std::string size_k = "size";
    inline const std::string type_k = "type";
    inline const std::string subtype_k = "subtype";
    inline const std::string alignment_k = "alignment";
    inline const std::string armor_class_k = "armor_class";
    inline const std::string hit_points_k = "hit_points";
    inline const std::string hit_dice_k = "hit_dice";
    inline const std::string speed_k = "speed";
    inline const std::string alt_speeds_k = "alternate_speeds";
    inline const std::string condition_k = "condition";
    inline const std::string challenge_rating_k = "challenge_rating";
    inline const std::string str_k = "strength";
    inline const std::string dex_k = "dexterity";
    inline const std::string con_k = "constitution";
    inline const std::string int_k = "intelligence";
    inline const std::string wis_k = "wisdom";
    inline const std::string chr_k = "charisma";
    inline const std::string str_sv_k = "strength_save";
    inline const std::string dex_sv_k = "dexterity_save";
    inline const std::string con_sv_k = "constitution_save";
    inline const std::string int_sv_k = "intelligence_save";
    inline const std::string wis_sv_k = "wisdom_save";
    inline const std::string chr_sv_k = "charisma_save";
    inline const std::string languages_k = "languages";
    inline const std::string history_k = "history";
    inline const std::string perception_k = "perception";
    inline const std::string dmg_vuls_k = "damage_vulnerabilities";
    inline const std::string dmg_rsts_k = "damage_resistances";
    inline const std::string dmg_imns_k = "damage_immunities";
    inline const std::string cond_imns_k = "condition_immunities";
    inline const std::string senses_k = "senses";
    inline const std::string spcl_abls_k = "special_abilities";
    inline const std::string atk_bonus_k = "attack_bonus";
    inline const std::string dmg_bonus_k = "damage_bonus";
    inline const std::string dmg_dice_k = "damage_dice";
    inline const std::string actions_k = "actions";
    inline const std::string reactions_k = "reactions";
    inline const std::string leg_actions_k = "legendary_actions";
    inline const std::string image_filename_k = "image_file";
} // end namespace keys

#endif
