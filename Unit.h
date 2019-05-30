#ifndef UNIT_H
#define UNIT_H

#include <string_view>

class Unit {
    public:

        // Copy and move (disallowed)
        Unit(const Unit& u) = delete;
        Unit& operator=(const Unit& u) = delete;
        Unit(Unit&& u) = delete;
        Unit& operator=(Unit&& u) = delete;

        // Get member values
        inline constexpr int value() const noexcept { return _value; }
        inline constexpr std::string_view name() const noexcept { return _name; }
        inline constexpr std::string_view plural_name() const noexcept { return _pl_name; }
        inline constexpr std::string_view abbreviation() const noexcept { return _abbr; }


    protected:

        constexpr Unit(const int& value, const char* name, const char* pl_name, const char* abbr) : _value(value), _name(name), _pl_name(pl_name), _abbr(abbr) {}

        int _value;
        std::string_view _name;
        std::string_view _pl_name;
        std::string_view _abbr;
};

#endif