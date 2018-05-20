//
// Created by adrja on 20/05/2018.
//

#ifndef JIMP_EXERCISES_SERIALIZER_H
#define JIMP_EXERCISES_SERIALIZER_H


#include <ostream>
#include <vector>
#include <functional>

namespace academia {

    class Serializable;

    class Serializer {
    public:
        Serializer(std::ostream *out) : out_(out) {}

        virtual void IntegerField(const std::string &field_name, int value) =0;

        virtual void DoubleField(const std::string &field_name, double value) =0;

        virtual void StringField(const std::string &field_name, const std::string &value) =0;

        virtual void BooleanField(const std::string &field_name, bool value) =0;

        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value) =0;

        virtual void ArrayField(const std::string &field_name,
                                const std::vector<std::reference_wrapper<const academia::Serializable>> &value) =0;

        virtual void Header(const std::string &object_name) =0;

        virtual void Footer(const std::string &object_name) =0;

    protected:
        std::ostream *out_;
    };
}


//        Serializer(std::ostream *out);
//
//        void IntegerField(const std::string &field_name, int value) override;
//        void DoubleField(const std::string &field_name, double value) override;
//        void StringField(const std::string &field_name, const std::string &value) override;
//        void BooleanField(const std::string &field_name, bool value) override;
//        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;
//        void ArrayField(const std::string &field_name,
//                        const vector<reference_wrapper<const academia::Serializable>> &value) override;
//        void Header(const std::string &object_name) override;
//        void Footer(const std::string &object_name) override;


#endif //JIMP_EXERCISES_SERIALIZER_H
