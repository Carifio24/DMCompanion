#include "spell_builder.h"

#include <iostream>

namespace DnD {

SpellBuilder& SpellBuilder::set_name(const std::string& name) { this->name = name; return *this; }
SpellBuilder& SpellBuilder::set_description(const std::string& description) { this->description = description; return *this; }
SpellBuilder& SpellBuilder::set_higher_level(const std::string& higher_level) { this->higher_level = higher_level; return *this; }
SpellBuilder& SpellBuilder::set_page(const int page) { this->page = page; return *this; }
SpellBuilder& SpellBuilder::set_range(const Distance& range) { this->range = range; return *this; }
SpellBuilder& SpellBuilder::set_components(const std::array<bool,3>& components) { this->components = components; return *this; }
SpellBuilder& SpellBuilder::set_material(const std::string& material) { this->material = material; return *this; }
SpellBuilder& SpellBuilder::set_ritual(const bool& ritual) { this->ritual = ritual; return *this; }
SpellBuilder& SpellBuilder::set_duration(const Duration& duration) { this->duration = duration; return *this; }
SpellBuilder& SpellBuilder::set_concentration(const bool& concentration) { this->concentration = concentration; return *this; }
SpellBuilder& SpellBuilder::set_casting_time(const std::string& casting_time) { this->casting_time = casting_time; return *this; }
SpellBuilder& SpellBuilder::set_level(const int level) { this->level = level; return *this; }
SpellBuilder& SpellBuilder::set_school(const School& school) { this->school = std::cref(school); return *this; }
SpellBuilder& SpellBuilder::set_classes(const std::vector<CasterClass>& classes) { this->classes = classes; return *this; }
SpellBuilder& SpellBuilder::set_sourcebook(const Sourcebook& sourcebook) { this->sourcebook = std::cref(sourcebook); return *this; }

SpellBuilder& SpellBuilder::add_class(const CasterClass& cc) { classes.push_back(cc); return *this; }

Spell SpellBuilder::build() const {
    return Spell(name, description, higher_level, page, range, components, material, ritual, duration, concentration, casting_time, level, school, classes, sourcebook);
}

void SpellBuilder::reset() {
    name.clear();
    description.clear();
    higher_level.clear();
    page = 0;
    range = Distance();
    components = { false, false, false };
    material.clear();
    ritual = false;
    duration = Duration();
    concentration = false;
    casting_time.clear();
    level = 0;
    school = School::Abjuration;
    classes.clear();
    sourcebook = Sourcebook::PlayersHandbook;
}

Spell SpellBuilder::build_and_reset() {
    Spell spell = build();
    reset();
    return spell;
}

} // end namespace DnD