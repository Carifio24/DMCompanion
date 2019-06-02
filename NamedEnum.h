#ifndef NAMED_ENUM_H
#define NAMED_ENUM_H

#include <vector>
#include <iostream>
#include <string_view>

using namespace std::literals::string_view_literals;

namespace DnD {

template <typename NEType>
class NamedEnum {

    public:

        // The class instances
        struct Instances;

        // Copy and move (disallowed)
        NamedEnum(const NamedEnum&) = delete;
        NamedEnum& operator=(const NamedEnum&) = delete;
        NamedEnum(NamedEnum&&) = delete;
        NamedEnum& operator=(NamedEnum&&) = delete;

        // Get member values
        inline constexpr int value() const noexcept { return _value; }
        inline constexpr std::string_view name() const noexcept { return _name; }

        // Create a value from a string
        static const NamedEnum& fromString(const std::string& s);


    protected:

        constexpr NamedEnum(const int& value, const std::string_view& name) : _value(value), _name(name) {
            NamedEnum::Instances::instances.push_back(static_cast<NEType*>(this));
            std::cout << "Adding to instances" << std::endl;
            std::cout << "Instances count is now " << NamedEnum::Instances::instances.size() << std::endl;
        }

        const int _value;
        const std::string_view _name;
    
};


template <typename NEType>
struct NamedEnum<NEType>::Instances {
    static const std::vector<const NEType*> instances;
};


template <typename NEType>
const NamedEnum<NEType>& NamedEnum<NEType>::fromString(const std::string& s) {

    for (auto inst : NamedEnum<NEType>::Instances::instances) {
        if ( (s == inst->name()) || (s == inst->plural_name()) || (s == inst->abbreviation()) ) {
            return *inst;
        }
    }

    throw std::runtime_error("Not a valid unit string");
}

} // end namespace DnD

#endif