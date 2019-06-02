#include "LengthUnit.h"
#include "Distance.h"
#include "Duration.h"

#include <iostream>

using namespace DnD;

int main() {
    Distance r(DnD::DistanceType::Self, 0, LengthUnits::Foot, "Self");
    Duration d(DnD::DurationType::Instantaneous, 0, TimeUnits::Second, "Instantaneous");
}