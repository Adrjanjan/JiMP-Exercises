//
// Created by adrja on 20/05/2018.
//

#ifndef JIMP_EXERCISES_ROOM_H
#define JIMP_EXERCISES_ROOM_H

#include <utility>
#include <string>
#include "Serializable.h"

namespace academia {

    class Room : public Serializable {
    public:
        enum Type {
            COMPUTER_LAB = 0,
            LECTURE_HALL = 1,
            CLASSROOM = 2
        };

        Room(int index, std::string name, Type type);

        void Serialize(Serializer *serializer) const override;

    private:
        int index_;
        std::string name_;
        Type type_;

        const std::string TYPES[3] = {"COMPUTER_LAB",
                                      "LECTURE_HALL",
                                      "CLASSROOM"};
    };
}

#endif //JIMP_EXERCISES_ROOM_H
