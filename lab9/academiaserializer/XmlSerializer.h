//
// Created by adrja on 20/05/2018.
//

#ifndef JIMP_EXERCISES_XMLSERIALIZER_H
#define JIMP_EXERCISES_XMLSERIALIZER_H

#include "Serializer.h"

namespace academia {

    class XmlSerializer : public Serializer {
    public:
        XmlSerializer(std::ostream *out);

        void IntegerField(const std::string &field_name, int value) override;

        void DoubleField(const std::string &field_name, double value) override;

        void StringField(const std::string &field_name, const std::string &value) override;

        void BooleanField(const std::string &field_name, bool value) override;

        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;

        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override;

        void Header(const std::string &object_name) override;

        void Footer(const std::string &object_name) override;
    };

}
#endif //JIMP_EXERCISES_XMLSERIALIZER_H
