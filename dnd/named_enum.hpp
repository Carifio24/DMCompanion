#ifndef NAMED_ENUM_H
#define NAMED_ENUM_H

#include <array>
#include <string>
#include <cctype>
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

        // The index in instances
        constexpr int index() const noexcept;

        // Test for equality
        constexpr bool operator==(const NamedEnum& other) const noexcept { return _name == other._name; }
        constexpr bool operator!=(const NamedEnum& other) const noexcept { return _name != other._name; }
        constexpr bool operator<(const NamedEnum& other) const noexcept;
    
        // Create a value from a string
        static const NEType& from_name(const std::string& s, const std::function<void(std::string&)>& transform);
        static const NEType& from_name(const std::string& s);
        static const NEType& from_lc_name(const std::string& s);
        static const NEType& from_uc_name(const std::string& s);

        // Create a value from an arbitrary member
        // The first function allows an arbitrary transformation to be defined
        template <typename T, typename U>
        //template <typename T, typename U, typename = std::enable_if_t<std::is_convertible_v<U,T> > >
        static const NEType& from_member(const T& t, U (NEType::* mem_ptr)(void) const);
        template <typename T, typename U>
        static const NEType& from_member(T t, U (NEType::* mem_ptr)(void) const, const std::function<void(T&)>& transform);


    protected:

        constexpr NamedEnum(const std::string_view& name) : _name(name) {}
        const std::string_view _name;
    
};

// Get the index in instances
template <typename NEType>
constexpr int NamedEnum<NEType>::index() const noexcept {
    for (size_t i = 0; i < n_values(); ++i) {
        if (static_cast<const NEType*>(this) == NEType::Instances::instances[i]) {
            return i;
        }
    }
    return -1;
}

// Comparison
template <typename NEType>
constexpr bool NamedEnum<NEType>::operator<(const NamedEnum<NEType>& other) const noexcept {
    return this->index() < other.index();
}

// Functions for returning a reference to a value from its name
template <typename NEType>
const NEType& NamedEnum<NEType>::from_name(const std::string& s, const std::function<void(std::string&)>& transform) {

    // Check whether the name agrees with any of the cases
    std::string nm;
    for (auto inst : NEType::Instances::instances) {
        nm = std::string(inst->_name);
        transform(nm);
        if ( s == nm ) {
            return *inst;
        }
    }
    throw std::runtime_error("Not a valid string -- " + s);
}

template <typename NEType>
const NEType& NamedEnum<NEType>::from_name(const std::string& s) {
    // Check whether the name agrees with any of the cases
    for (auto inst : NEType::Instances::instances) {
        if ( s == inst->_name ) {
            return *inst;
        }
    }
    throw std::runtime_error("Not a valid string -- " + s);
}

template <typename NEType>
const NEType& NamedEnum<NEType>::from_lc_name(const std::string& s) {
    std::function<void(std::string&)> make_lc = [](std::string& s) { std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) -> unsigned char { return std::tolower(c); }); };
    return from_name(s, make_lc);
}

template <typename NEType>
const NEType& NamedEnum<NEType>::from_uc_name(const std::string& s) {
    std::function<void(std::string&)> make_uc = [](std::string& s) { std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) -> unsigned char { return std::toupper(c); }); };
    return from_name(s, make_uc);
}



// These function allows one to get a reference to a value from an arbitrary member value
// U must be convertible to T
// "U (NEType::* mem_ptr)(void) const" declares a pointer to a const member function with return type U, named mem_ptr
template <typename NEType>
template <typename T, typename U>
const NEType& NamedEnum<NEType>::from_member(const T& t, U (NEType::* mem_ptr)(void) const) {

    // Check whether the value agrees with any of the cases
    for (auto inst : NEType::Instances::instances) {
        if ( t == (inst->*mem_ptr)() ) {
            return *inst;
        }
    }
    throw std::runtime_error("Not a valid member value -- " + t);
}

template <typename NEType>
template <typename T, typename U>
const NEType& NamedEnum<NEType>::from_member(T t, U (NEType::* mem_ptr)(void) const, const std::function<void(T&)>& transform) {

    // Apply the transformation and call the default from_member
    transform(t);
    return from_member(t, mem_ptr);
}


template <typename NEType>
constexpr int NamedEnum<NEType>::n_values() { 
    int i = 0;
    for (const auto& x : NEType::Instances::instances) { ++i; }
    return i;
}

} // end namespace DnD

#endif