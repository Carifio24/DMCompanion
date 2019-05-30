#ifndef QUANTITY_HPP
#define QUANTITY_HPP

#include <string>
#include <type_traits>

template <typename QuantityType, typename UnitType, typename = std::enable_if_t<std::is_enum_v<QuantityType> > >
class Quantity {

    public:

        Quantity(const QuantityType& type, const int& value, UnitType& unit, const std::string& str="") : _type(type), _value(value), _unit(unit), _str(str) {}

        QuantityType quantity_type() const noexcept { return _type; }
        int value() const noexcept { return _value; }
        UnitType unit_type() const noexcept { return _unit; }
        virtual std::string string() const;

        bool operator<(const Quantity& other) const {
            if (_type == other._type) {
                return baseValue() < other.baseValue();
            }
            return _type < other._type;
        }

    protected:
        int baseValue() const { return _value * _unit.value(); }

        QuantityType _type;
        int _value;
        UnitType& _unit;
        std::string _str;

};

#endif