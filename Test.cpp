#include "NamedEnum.h"
//#include "Unit.h"
#include "LengthUnit.h"
#include "TimeUnit.h"
#include "Sourcebook.h"

#include <iostream>

using namespace DnD;

int main() {
    int i = 0;
    std::cout << "There are "<< LengthUnit::n_values() << " length units" << std::endl;
    std::cout << "There are "<< TimeUnit::n_values() << " time units" << std::endl;
    std::cout << "There are " << Sourcebook::n_values() << " sourcebooks" << std::endl;
    std::cout << LengthUnit::fromName("foot").name() << std::endl;
    std::cout << Sourcebook::fromAbbreviation("PHB").name() << std::endl;
    //std::cout << sizeof(LengthUnits::instances)/sizeof(LengthUnits::instances[0]) << std::endl;
    //Distance r(DnD::DistanceType::Self, 0, LengthUnits::Foot, "Self");
    //Duration d(DnD::DurationType::Instantaneous, 0, TimeUnits::Second, "Instantaneous");
}