//
// Created by adrja on 20/05/2018.
//

#include <iosfwd>
#include "XmlSerializer.h"
#include "Serializable.h"

academia::XmlSerializer::XmlSerializer(std::ostream *out) : Serializer(out) {

}

void academia::XmlSerializer::IntegerField(const std::string &field_name, int value) {
    (*out_) << "<" << field_name << ">" << value << "<\\" << field_name << ">";
}

void academia::XmlSerializer::DoubleField(const std::string &field_name, double value) {
    (*out_) << "<" << field_name << ">" << value << "<\\" << field_name << ">";
}

void academia::XmlSerializer::StringField(const std::string &field_name, const std::string &value) {
    (*out_) << "<" << field_name << ">" << value << "<\\" << field_name << ">";
}

void academia::XmlSerializer::BooleanField(const std::string &field_name, bool value) {
    (*out_) << "<" << field_name << ">" << value << "<\\" << field_name << ">";
}

void academia::XmlSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
    (*out_) << "<" << field_name << ">";
    value.Serialize(this);
    (*out_) << "<\\" << field_name << ">";
}

void academia::XmlSerializer::ArrayField(const std::string &field_name,
                                         const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
    (*out_) << "<" << field_name << ">";
    for (const auto &item : value) {
        item.get().Serialize(this);
    }
    (*out_) << "<\\" << field_name << ">";
}

void academia::XmlSerializer::Header(const std::string &object_name) {
    (*out_) << "<" << object_name << ">";
}

void academia::XmlSerializer::Footer(const std::string &object_name) {
    (*out_) << "<\\" << object_name << ">";
}
