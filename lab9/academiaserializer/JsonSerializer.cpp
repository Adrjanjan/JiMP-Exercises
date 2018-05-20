//
// Created by adrja on 20/05/2018.
//

#include <iosfwd>
#include "JsonSerializer.h"

academia::JsonSerializer::JsonSerializer(std::ostream *out) : Serializer(out), separate_(false) {}

void academia::JsonSerializer::IntegerField(const std::string &field_name, int value) {
    Separate();
    (*out_) << "\"" << field_name << "\": " << value;
}

void academia::JsonSerializer::DoubleField(const std::string &field_name, double value) {
    Separate();
    (*out_) << "\"" << field_name << "\": " << value;
}

void academia::JsonSerializer::StringField(const std::string &field_name, const std::string &value) {
    Separate();
    (*out_) << "\"" << field_name << "\": \"" << value << "\"";
}

void academia::JsonSerializer::BooleanField(const std::string &field_name, bool value) {
    Separate();
    (*out_) << "\"" << field_name << "\": " << value;
}

void academia::JsonSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
    Separate();
    (*out_) << "\"" << field_name << "\": ";
    value.Serialize(this);
}

void academia::JsonSerializer::ArrayField(const std::string &field_name,
                                          const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {

    Separate();
    (*out_) << "\"" << field_name << "\": [";
    separate_ = false;
    for (const auto &item : value) {
        Separate();
        separate_ = false;
        item.get().Serialize(this);
    }

    (*out_) << "]";

}

void academia::JsonSerializer::Header(const std::string &object_name) {
    (*out_) << "{";
}

void academia::JsonSerializer::Footer(const std::string &object_name) {
    (*out_) << "}";
}

void academia::JsonSerializer::Separate() {
    if (separate_) {
        (*out_) << ", ";
    } else {
        separate_ = true;
    }

}
