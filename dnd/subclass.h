#ifndef SUBCLASS_H
#define SUBCLASS_H

#include "named_enum.hpp"

namespace DnD {

class SubclassImpl : public NamedEnumImpl<SubclassImpl> {

    public:
        // The class instances
        struct Instances;

        inline constexpr std::string_view abbreviation() const noexcept { return _abbr; }

        static const SubclassImpl& from_abbreviation(const std::string& s) {
            return from_member(s, &SubclassImpl::abbreviation);
        }

    private:
        constexpr SubclassImpl(const std::string_view& name, const std::string_view& abbr) : NamedEnumImpl<SubclassImpl>(name), _abbr(abbr) {}
        const std::string_view _abbr;
};

using Subclasses = SubclassImpl::Instances;

class Subclass : public NamedEnum<SubclassImpl,Subclass> {

    public:
 
        Subclass(const SubclassImpl& sci) : NamedEnum<SubclassImpl,Subclass>(sci) {}

        inline std::string_view abbreviation() const noexcept { return _impl.get().abbreviation(); }

};

} // end namespace DnD

#endif