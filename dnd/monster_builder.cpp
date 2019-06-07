#include "monster_builder.h"

namespace DnD {

MonsterBuilder& MonsterBuilder::set_history(const int history) { this->history = history; return *this; }
MonsterBuilder& MonsterBuilder::set_image_filename(const std::string& image_filename) { this->image_filename = image_filename; return *this; }

Monster MonsterBuilder::build() const {
    Monster(name, size, type, subtype, alignment, cr, hit_dice, ac, hp, speeds, alt_speeds, str, dex, con, intl, wis, chr, str_sv, dex_sv, con_sv, int_sv, wis_sv, chr_sv, prcp, dmg_vuls, dmg_rsts, dmg_imns, cond_imns, senses, pass_prcp, languages, spcl_abls, actions, leg_actions, history, image_filename);
}

void MonsterBuilder::reset() {
    CreatureBuilder::reset();
    history = 0;
    image_filename.clear();
}

Monster MonsterBuilder::build_and_reset() {
    Monster monster = build();
    reset();
    return monster;
}

} // end namespace DnD