#ifndef SPELL_H
#define SPELL_H

#include "enumerations.h"
#include "duration.h"
#include "sourcebook.h"
#include "school.h"
#include "distance.h"
#include "caster_class.h"

#include <string>
#include <array>
#include <vector>

namespace DnD {

class Spell {

    public:

        // Getters
        std::string name() const noexcept { return _name; }
        std::string description() const noexcept { return _description; }
        std::string higher_level() const noexcept { return _higher_level; }
        int page() const noexcept { return _page; }
        Distance range() const noexcept { return _range; }
        std::array<bool,3> components() const noexcept { return _components; }
        std::string material() const noexcept { return _material; }
        bool ritual() const noexcept { return _ritual; }
        Duration duration() const noexcept { return _duration; }
        bool concentration() const noexcept { return _concentration; }
        std::string casting_time() const noexcept { return _casting_time; }
        int level() const noexcept { return _level; }
        const School& school() const noexcept { return _school.get(); }
        const Sourcebook& sourcebook() const noexcept { return _sourcebook.get(); }
        std::vector<std::reference_wrapper<const CasterClass>> classes() const noexcept { return _classes; }

        // Other methods
        std::string components_string() const;
        std::string classes_string() const;
        bool usable_by(const CasterClass& cc) const;

        // Constructor
        Spell(const std::string& name, const std::string& description, const std::string& higher_level, const int page, const Distance& range, const std::array<bool,3>& components, const std::string& material, const bool ritual, const Duration& duration, const bool concentration, const std::string& casting_time, const int level, const School& school, const std::vector<std::reference_wrapper<const CasterClass>>& classes, const Sourcebook& sourcebook)
        : _name(name), _description(description), _higher_level(higher_level), _page(page), _range(range), _components(components), _material(material), _ritual(ritual), _duration(duration), _concentration(concentration), _casting_time(casting_time), _level(level), _school(school), _classes(classes), _sourcebook(sourcebook) {}

        // Default constructor
        Spell() : Spell("", "", "", 0, Distance(), std::array<bool,3>(), "", false, Duration(), false, "", 0, std::cref(Schools::Abjuration), std::vector<std::reference_wrapper<const CasterClass>>(), std::cref(Sourcebooks::PlayersHandbook)) {}


    private:

        // Member values
        std::string _name;
        std::string _description;
        std::string _higher_level;
        int _page;
        Distance _range;
        std::array<bool,3> _components;
        std::string _material;
        bool _ritual;
        Duration _duration;
        bool _concentration;
        std::string _casting_time;
        int _level;
        std::reference_wrapper<const School> _school;
        std::vector<std::reference_wrapper<const CasterClass>> _classes;
        std::reference_wrapper<const Sourcebook> _sourcebook;

};

} // end namespace DnD

#endif // SPELL_H

