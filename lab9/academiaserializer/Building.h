//
// Created by adrja on 20/05/2018.
//

#ifndef JIMP_EXERCISES_BUILDING_H
#define JIMP_EXERCISES_BUILDING_H

#include "Room.h"

namespace academia {

    class Building : public Serializable {
    public:
        Building(int id, std::string name, std::initializer_list<Room> rooms);

        void Serialize(Serializer *serializer) const override;

        int Id() const;

    private:
        int id_;
        std::string name_;
        std::vector<std::reference_wrapper<const Serializable>> rooms_;
    };

}
#endif //JIMP_EXERCISES_BUILDING_H
