#ifndef SPELL_H
#define SPELL_H

#include "Enumerations.h"
#include "Duration.h"
#include "Sourcebook.h"
#include "School.h"
#include "Distance.h"
#include "CasterClass.h"

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
        const School& school() const noexcept { return _school; }
        const Sourcebook& sourcebook() const noexcept { return _sourcebook; }
        std::vector<CasterClass* const> classes() const noexcept { return _classes; }

        // Other methods
        std::string components_string() const;
        std::string classes_string() const;
        bool usable_by(const CasterClass& cc) const;


    private:

        // Member values
        const int _index;
        const std::string _name;
        const std::string _description;
        const std::string _higher_level;
        const int _page;
        const Distance _range;
        const std::array<bool,3> _components;
        const std::string _material;
        const bool _ritual;
        const Duration _duration;
        const bool _concentration;
        const std::string _casting_time;
        const int _level;
        const bool _favorite;
        const School& _school;
        const Sourcebook& _sourcebook;
        const std::vector<CasterClass* const> _classes;

        // Constructor
        Spell(const std::string& name, const std::string& description, const std::string& higher_level, const int& page, const Distance& range, const std::array<bool,3>& components, const std::string& material, const bool& ritual, const Duration& duration, const bool& concentration, const std::string& casting_time, const int& level, const School& school, const std::vector<CasterClass&>& classes, const Sourcebook& sourcebook)
        : _name(name), _description(description), _higher_level(higher_level), _page(page), _range(range), _components(components), _material(material), _ritual(ritual), _duration(duration), _concentration(concentration), _casting_time(casting_time), _level(level), _school(school), _classes(classes), _sourcebook(sourcebook) {}

        friend class SpellBuilder;
};

} // end namespace DnD

#endif // SPELL_H

