//
// Created by adrja on 20/05/2018.
//

#include <string>
#include <vector>
#include "Building.h"
#include "Serializer.h"


academia::Building::Building(int id, std::string name, std::initializer_list<Room> rooms) : id_(id), name_(name) {
    for (const auto &room : rooms) {
        rooms_.emplace_back(room);
    }
}

void academia::Building::Serialize(Serializer *serializer) const {
    serializer->Header("building");
    serializer->IntegerField("id", id_);
    serializer->StringField("name", name_);
    serializer->ArrayField("rooms", rooms_);
    serializer->Footer("building");
}

int academia::Building::Id() const {
    return id_;
}
