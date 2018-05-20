//
// Created by adrja on 20/05/2018.
//

#include "Room.h"

void academia::Room::Serialize(academia::Serializer *serializer) const {
    serializer->Header("room");
    serializer->IntegerField("id", index_);
    serializer->StringField("name", name_);
    serializer->StringField("type", TYPES[type_]);
    serializer->Footer("room");
}

academia::Room::Room(int index, std::string name, academia::Room::Type type) {
    index_ = index;
    name_ = name;
    type_ = type;
}
