//
// Created by adrja on 02.04.2018.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include <experimental/optional>
#include <string>

namespace nets {
    class JsonValue {
    public:
        JsonValue(int integer);

        JsonValue(double real_num);

        JsonValue(std::string str);

        JsonValue(bool logic_value);

        JsonValue(std::vector<JsonValue> _vector);

        JsonValue(std::map<std::string, JsonValue> object);

        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;

        std::string ToString() const;

    private:
        enum JSON_type_ {
            INTEGER = 1, REAL = 2, STRING = 3, LOGIC = 4, VECTOR = 5, OBJECT = 6
        };
        int this_obj_type_;
        int integer_;
        double real_;
        std::string string_;
        bool logic_;
        std::vector<nets::JsonValue> vector_;
        std::map<std::string, nets::JsonValue> object_;
    };
}


#endif //JIMP_EXERCISES_SIMPLEJSON_H
