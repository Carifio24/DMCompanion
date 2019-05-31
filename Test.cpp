#include "LengthUnit.h"
#include "Range.h"

#include <iostream>

using namespace DnD;

int main() {
    Range r(DnD::RangeType::Self, 0, LengthUnits::Foot, "Self");
}