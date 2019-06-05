#ifndef QUANTITY_HPP
#define QUANTITY_HPP

#include <string>
#include <functional>
#include <type_traits>

// Note that the UnitType and QuantityType members are references
// This ensures that there is no copying of these instances
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

        // Comparison operators
        bool operator<(const Quantity& other) const {
            if (_type == other._type) {
                return base_value() < other.base_value();
            }
            return _type < other._type;
        }

        bool operator=(const Quantity& other) const {
            return (_type == other._type) && (base_value() == other.base_value());
        }

    protected:

        // For use by subclasses
        int base_value() const noexcept { return _value * _unit.value(); }

        // Member values
        std::reference_wrapper<QuantityType> _type;
        int _value;
        std::reference_wrapper<UnitType> _unit;
        std::string _str;

};

#endif