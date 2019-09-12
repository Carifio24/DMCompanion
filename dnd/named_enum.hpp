#ifndef NAMED_ENUM_HPP
#define NAMED_ENUM_HPP

#include "named_enum_impl.hpp"

template <typename ImplType, typename Derived>
class NamedEnum : public ImplType::Instances {

    public:

        // Constructor
        NamedEnum<ImplType,Derived>(const ImplType& impl) : _impl(impl) {}

        // Copy
        NamedEnum<ImplType,Derived>(const NamedEnum<ImplType,Derived>&) = default;
        NamedEnum<ImplType,Derived>& operator=(const NamedEnum<ImplType,Derived>&) = default;

        // Get member values
        inline std::string_view name() const noexcept { return _impl.get().name(); }

        // Get the number of values
        static constexpr int n_values() noexcept { return ImplType::n_values(); }

        // The index in instances
        int index() const noexcept { return _impl.get().index(); }

        // Get the internal NamedEnumImpl
        const ImplType& get() const noexcept { return _impl.get(); }

        // The instances
        static std::vector<Derived> instances() noexcept {
            static std::vector<Derived> insts;
            if (insts.size() != n_values()) {
                insts.clear();
                insts.reserve(n_values());
                for (int i = 0; i < n_values(); ++i) {
                    insts.emplace_back(*ImplType::Instances::instances[i]);
                }
            }
            return insts;
        }

        // Test for equality
        constexpr bool operator==(const NamedEnum<ImplType,Derived>& other) const noexcept { return _impl.get() == other._impl.get(); }
        constexpr bool operator!=(const NamedEnum<ImplType,Derived>& other) const noexcept { return _impl.get() != other._impl.get(); }
        constexpr bool operator<(const NamedEnum<ImplType,Derived>& other) const noexcept { return _impl.get() < other._impl.get(); }
        constexpr bool operator==(const ImplType& nei) const noexcept { return _impl.get() == nei; }
        constexpr bool operator!=(const ImplType& nei) const noexcept { return _impl.get() != nei; }
        constexpr bool operator<(const ImplType& nei) const noexcept { return _impl.get() < nei; }

        // Create a value from a string
        static Derived from_name(const std::string& s, const std::function<void(std::string&)>& transform) { return Derived(ImplType::from_name(s, transform)); }
        static Derived from_name(const std::string& s) { return Derived(ImplType::from_name(s)); }
        static Derived from_lc_name(const std::string& s) { return Derived(ImplType::from_lc_name(s)); }
        static Derived from_uc_name(const std::string& s) { return Derived(ImplType::from_uc_name(s)); }

        // Create a value from an arbitrary member
        // The first function allows an arbitrary transformation to be defined
        template <typename T, typename U>
        //template <typename T, typename U, typename = std::enable_if_t<std::is_convertible_v<U,T> > >
        static Derived from_member(const T& t, U (Derived::* mem_ptr)(void) const) { return Derived(ImplType::from_member(t, mem_ptr)); }
        template <typename T, typename U>
        static Derived from_member(T t, U (Derived::* mem_ptr)(void) const, const std::function<void(T&)>& transform) { return Derived(ImplType::from_member(t, mem_ptr, transform)); }

    protected:
        std::reference_wrapper<const ImplType> _impl;

        // Default constructor - for internal use only
        NamedEnum<ImplType,Derived>() : NamedEnum<ImplType,Derived>(ImplType::Instances::instances[0]) {}

};

#endif