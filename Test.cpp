#include "LengthUnit.h"
#include "Distance.h"

#include <iostream>

using namespace DnD;

int main() {
    Distance r(DnD::DistanceType::Self, 0, LengthUnits::Foot, "Self");
}