#ifndef SPELL_BUILDER_H
#define SPELL_BUILDER_H

#include <array>
#include <string>
#include <vector>

#include "spell.h"
#include "distance.h"
#include "duration.h"
#include "enumerations.h"

namespace DnD {

class SpellBuilder {

    public:

        // Constructor
        SpellBuilder() {}

        // Setter methods
        SpellBuilder& set_name(const std::string& name);
        SpellBuilder& set_description(const std::string& description);
        SpellBuilder& set_higher_level(const std::string& higher_level);
        SpellBuilder& set_page(const int page);
        SpellBuilder& set_range(const Distance& range);
        SpellBuilder& set_components(const std::array<bool,3>& components);
        SpellBuilder& set_material(const std::string& material);
        SpellBuilder& set_ritual(const bool& ritual);
        SpellBuilder& set_duration(const Duration& duration);
        SpellBuilder& set_concentration(const bool& concentration);
        SpellBuilder& set_casting_time(const std::string& casting_time);
        SpellBuilder& set_level(const int level);
        SpellBuilder& set_school(const School& school);
        SpellBuilder& set_classes(const std::vector<std::reference_wrapper<const CasterClass>>& classes);
        SpellBuilder& set_sourcebook(const Sourcebook& sourcebook);

        SpellBuilder& add_class(const CasterClass& cc);

        // Building methods
        Spell build() const;
        void reset();
        Spell build_and_reset();

    private:

        // Member values
        std::string name;
        std::string description;
        std::string higher_level;
        int page;
        Distance range;
        std::array<bool,3> components;
        std::string material;
        bool ritual;
        Duration duration;
        bool concentration;
        std::string casting_time;
        int level;
        std::reference_wrapper<const School> school = std::cref(Schools::Abjuration);
        std::vector<std::reference_wrapper<const CasterClass>> classes;
        std::reference_wrapper<const Sourcebook> sourcebook = std::cref(Sourcebooks::PlayersHandbook);
};

} // end namespace DnD

#endif