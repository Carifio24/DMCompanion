#ifndef QUANTITY_HPP
#define QUANTITY_HPP

#include <string>
#include <type_traits>

// Note that the UnitType member is a reference
// This ensures that there is no copying of the UnitType instances
template <typename QuantityType, typename UnitType>
class Quantity {

    public:

        // Constructor
        Quantity(const QuantityType& type, const int& value, const UnitType& unit, const std::string& str="") : _type(type), _value(value), _unit(unit), _str(str) {}

        // Get member values
        // Notice that string() is virtual
        QuantityType quantity_type() const noexcept { return _type; }
        int value() const noexcept { return _value; }
        UnitType unit_type() const noexcept { return _unit; }
        virtual std::string string() const = 0;

        // Comparison operator
        bool operator<(const Quantity& other) const {
            if (_type == other._type) {
                return base_value() < other.base_value();
            }
            return _type < other._type;
        }

    protected:

        // For use by subclasses
        int base_value() const noexcept { return _value * _unit.value(); }

        // Member values
        const QuantityType _type;
        const int _value;
        const UnitType& _unit;
        const std::string _str;

};

#endif