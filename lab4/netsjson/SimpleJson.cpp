//
// Created by adrja on 02.04.2018.
//

#include <utility>
#include <sstream>
#include <vector>
#include <map>

#include "SimpleJson.h"

std::string nets::JsonValue::ToString() const {
    std::string temp;

    switch (this_obj_type_) {
        case (INTEGER): {
            temp = std::to_string(integer_);
            break;
        }
        case (REAL)   : {
            std::stringstream ss;
            ss << real_;
            ss >> temp;
            break;
        }
        case (STRING) : {
            temp += "\"";
            for (auto i: string_) {
                if (i == '\\' || i == '\"') {
                    temp += '\\';
                }
                temp += i;
            }
            temp += "\"";
            break;
        }
        case (LOGIC)  : {
            if (logic_) temp = "true";
            else temp = "false";
            break;
        }
        case (VECTOR) : {
            temp = "[";
            for (const auto &i: vector_) {
                temp += i.ToString() + ", ";
            }
            temp.pop_back();
            temp.pop_back();
            temp += "]";
            break;
        }
        case (OBJECT) : {
            temp += "{";
            for (const auto &i: object_) {
                temp += "\"";
                for (auto j: i.first) {
                    if (j == '\\' || j == '\"') {
                        temp += '\\';
                    }
                    temp += j;
                }
                temp += "\": " + i.second.ToString() + ", ";
            }
            temp.pop_back();
            temp[temp.end()[-1]] = '}';
            break;
        }
        default:
            return temp;
    }
    return temp;
}

std::experimental::optional<nets::JsonValue> nets::JsonValue::ValueByName(const std::string &name) const {
    if (this_obj_type_ != OBJECT)
        return {};

    for (auto i: object_) {
        if (i.first == name) {
            return (i.second);
        }
    }
}

nets::JsonValue::JsonValue(int integer) {
    this_obj_type_ = INTEGER;
    integer_ = integer;
}

nets::JsonValue::JsonValue(double real_num) {
    this_obj_type_ = REAL;
    real_ = real_num;
}

nets::JsonValue::JsonValue(std::string str) {
    this_obj_type_ = STRING;
    string_ = std::move(str);
}

nets::JsonValue::JsonValue(bool logic_value) {
    this_obj_type_ = LOGIC;
    logic_ = logic_value;
}

nets::JsonValue::JsonValue(std::vector<nets::JsonValue> _vector) {
    this_obj_type_ = VECTOR;
    vector_ = std::move(_vector);
}

nets::JsonValue::JsonValue(std::map<std::string, nets::JsonValue> object) {
    this_obj_type_ = OBJECT;
    object_ = std::move(object);
}

