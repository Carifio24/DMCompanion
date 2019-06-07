#ifndef QUANTITY_HPP
#define QUANTITY_HPP

#include <string>
#include <functional>
#include <type_traits>

template <typename QuantityType, typename UnitType>
class Quantity {

    public:

        // Constructor
        Quantity(const QuantityType& type, const int& value, const UnitType& unit, const std::string& str="") : _type(type), _value(value), _unit(unit), _str(str) {}

        // Get member values
        // Notice that string() is virtual
        const QuantityType& quantity_type() const noexcept { return _type.get(); }
        int value() const noexcept { return _value; }
        const UnitType& unit_type() const noexcept { return _unit.get(); }
        virtual std::string string() const = 0;

        // Comparison operators
        bool operator<(const Quantity& other) const {
            if (_type.get() == other._type.get()) {
                return base_value() < other.base_value();
            }
            return _type .get() < other._type.get();
        }

        bool operator=(const Quantity& other) const {
            return (_type.get() == other._type.get()) && (base_value() == other.base_value());
        }

    protected:

        // For use by subclasses
        int base_value() const noexcept { return _value * _unit.get().value(); }

        // Member values
        std::reference_wrapper<const QuantityType> _type;
        int _value;
        std::reference_wrapper<const UnitType> _unit;
        std::string _str;

};

#endif