//
// Created by adrja on 20/05/2018.
//

#ifndef JIMP_EXERCISES_BUILDINGREPOSITORY_H
#define JIMP_EXERCISES_BUILDINGREPOSITORY_H

#include <experimental/optional>
#include "Serializable.h"
#include "Serializer.h"
#include "Building.h"

namespace academia {

    class BuildingRepository {
    public:
        BuildingRepository(std::initializer_list<Building> repo);

        void StoreAll(Serializer *serializer);

        void Add(Building building);

        std::experimental::optional<Building> operator[](int id) const;


    private:
        std::vector<std::reference_wrapper<const Building>> repo_;
    };

}
#endif //JIMP_EXERCISES_BUILDINGREPOSITORY_H
