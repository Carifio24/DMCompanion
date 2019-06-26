#ifndef MONSTER_BUILDER_H
#define MONSTER_BUILDER_H

#include "monster.h"
#include "creature_builder.h"

namespace DnD {

class MonsterBuilder : public CreatureBuilder {

    public:

        MonsterBuilder() : CreatureBuilder() {}

        MonsterBuilder& set_image_filename(const std::string& image_filename);

        Monster build() const;
        void reset();
        Monster build_and_reset();

    protected:
        std::string image_filename;

};

} // end namespace DnD

#endif