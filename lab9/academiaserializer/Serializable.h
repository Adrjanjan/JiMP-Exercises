//
// Created by adrja on 20/05/2018.
//

#ifndef JIMP_EXERCISES_SERIALIZABLE_H
#define JIMP_EXERCISES_SERIALIZABLE_H


#include "Serializer.h"

namespace academia {

    class Serializable {
    public:
        virtual void Serialize(Serializer *serializer) const = 0;
    };
}

#endif //JIMP_EXERCISES_SERIALIZABLE_H
