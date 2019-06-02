#ifndef SPEED_TYPE_H
#define SPEED_TYPE_H

class SpeedType : public NamedEnum<SpeedType> {

    public:

        // The class instances
        struct Instances;

    private:

        // Constructor
        constexpr SpeedType(const std::string_view& name) : NamedEnum<SpeedType>(name);

};

struct SpeedType::Instances {
    static inline constexpr const SpeedType Walking{"walking"sv};
    static inline constexpr const SpeedType Burrow{"burrow"sv};
    static inline constexpr const SpeedType Climb{"climb"sv};
    static inline constexpr const SpeedType Fly{"fly"sv};
    static inline constexpr const SpeedType Swim{"swim"sv};
    static inline constexpr const SpeedType* instances = { &Walking, &Burrow, &Climb, &Fly, &Swim };
};

using SpeedTypes = SpeedType::Instances;

#endif