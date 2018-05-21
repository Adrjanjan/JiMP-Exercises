//
// Created by adrja on 20/05/2018.
//

#include "BuildingRepository.h"

academia::BuildingRepository::BuildingRepository(std::initializer_list<Building> repo) {
    for (const auto &item : repo) {
        repo_.emplace_back(item);
    }
}

void academia::BuildingRepository::StoreAll(academia::Serializer *serializer) {
    serializer->Header("building_repository");
    std::vector<std::reference_wrapper<const Serializable>> buildings;
    for (const auto &building : repo_) {
        buildings.emplace_back(building);
    }
    serializer->ArrayField("buildings", buildings);
    serializer->Footer("building_repository");
}

void academia::BuildingRepository::Add(academia::Building building) {
    repo_.emplace_back(std::ref(building));
}

std::experimental::optional<academia::Building> academia::BuildingRepository::operator[](int id) const {
    for (const auto &item : repo_) {
        if (item.get().Id() == id) return item.get();
    }
    return {};
}
