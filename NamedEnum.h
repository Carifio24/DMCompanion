#ifndef NAMED_ENUM_H
#define NAMED_ENUM_H

#include <array>
#include <string>
#include <algorithm>
#include <functional>
#include <string_view>
#include <type_traits>

using namespace std::literals::string_view_literals;

namespace DnD {

template <typename NEType>
class NamedEnum {

    public:

        // Copy and move (disallowed)
        NamedEnum(const NamedEnum&) = delete;
        NamedEnum& operator=(const NamedEnum&) = delete;
        NamedEnum(NamedEnum&&) = delete;
        NamedEnum& operator=(NamedEnum&&) = delete;

        // Get member values
        inline constexpr std::string_view name() const noexcept { return _name; }

        // Get the number of values
        static constexpr int n_values();

        

        // Create a value from a string
        static const NEType& fromName(std::string s);

        // Create a value from an arbitrary member
        // The first function allows an arbitrary transformation to be defined
        template <typename T, typename U>
        //template <typename T, typename U, typename = std::enable_if_t<std::is_convertible_v<U,T> > >
        static const NEType& fromMember(T t, const U NEType::* mem_ptr, const std::function<void(T&)>& f);
        
        // Overload with the identity as the first argument
        template <typename T, typename U>
        //template <typename T, typename U, typename = std::enable_if_t<std::is_convertible_v<U,T> > >
        static const NEType& fromMember(T t, const U NEType::* mem_ptr);


    protected:

        constexpr NamedEnum(const std::string_view& name) : _name(name) {}
        const std::string_view _name;
    
};


template <typename NEType>
const NEType& NamedEnum<NEType>::fromName(std::string s) {

    // Check whether the name agrees with any of the cases
    for (auto inst : NEType::Instances::instances) {
        if ( s == inst->_name ) {
            return *inst;
        }
    }
    throw std::runtime_error("Not a valid string");
}


// U must be convertible to T
template <typename NEType>
template <typename T, typename U>
const NEType& NamedEnum<NEType>::fromMember(T t, const U NEType::* mem_ptr, const std::function<void(T&)>& f) {

    // Apply the relevant function
    f(t);

    // Check whether the value agrees with any of the cases
    for (auto inst : NEType::Instances::instances) {
        if ( t == inst->*mem_ptr ) {
            return *inst;
        }
    }
    throw std::runtime_error("Not a valid string");
}

//Overload with identity as the default function
template <typename NEType>
template <typename T, typename U>
const NEType& NamedEnum<NEType>::fromMember(T t, const U NEType::* mem_ptr) {
    std::function<void(T&)> id_func = [](T& t) { return t; };
    return NamedEnum<NEType>::fromMember(t, mem_ptr, id_func);
}

template <typename NEType>
constexpr int NamedEnum<NEType>::n_values() { 
    int i = 0;
    for (const auto& x : NEType::Instances::instances) { ++i; }
    return i;
}

} // end namespace DnD

#endif