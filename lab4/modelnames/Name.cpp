//
// Created by adrja on 02.04.2018.
//

#include <vector>
#include "Name.h"

model::Name::Name(const std::string &first_names_surname) {
    std::string temp{};
    short count = -1;
    bool prev_blank = false;
    std::vector<string> words;

    for (auto i:first_names_surname) {
        if (!std::isalpha(i) && i != '-') {
            if (prev_blank) continue;

            words.emplace_back(temp);
            prev_blank = true;
            temp.erase();
            ++count;
            continue;
        }

        temp += i;
        prev_blank = false;
    }
    words.emplace_back(temp);
    switch (count) {
        case 2: {
            third_name_ = words[2];
        }
        case 1: {
            second_name_ = words[1];
        }
        default: {
            first_name_ = words[0];
            last_name_ = words.end()[-1];
            break;
        }
    }
}

std::string model::Name::FirstName() const {
    return first_name_;
}

std::experimental::optional<std::string> model::Name::SecondName() const {
    if (second_name_.empty()) return {};
    optional<std::string> sec_name = second_name_;
    if (sec_name) {
        return *sec_name;
    }
}

std::experimental::optional<std::string> model::Name::ThirdName() const {
    if (third_name_.empty()) return {};
    optional<std::string> th_name = third_name_;
    if (th_name) {
        return *th_name;
    }
}

std::string model::Name::Surname() const {
    return last_name_;
}

std::string model::Name::ToFullInitials() const {
    std::string temp;
    temp += first_name_[0];
    temp += ".";

    if (!second_name_.empty()) {
        temp += " ";
        temp += second_name_[0];
        temp += ".";
    }
    if (!third_name_.empty()) {
        temp += " ";
        temp += third_name_[0];
        temp += ".";
    }
    temp += " ";
    temp += last_name_[0];
    temp += ".";
    return temp;
}

std::string model::Name::ToFirstNamesInitials() const {
    std::string temp = ToFullInitials();
    temp.pop_back();
    temp.pop_back();
    temp += Surname();
    return temp;
}

std::string model::Name::ToSurnameNames() const {
    if (!third_name_.empty())
        return last_name_ + " " + first_name_ + " " + second_name_ + " " + third_name_;
    if (!second_name_.empty())
        return last_name_ + " " + first_name_ + " " + second_name_;
    return last_name_ + " " + first_name_;
}

std::string model::Name::ToNamesSurname() const {
    if (!third_name_.empty())
        return first_name_ + " " + second_name_ + " " + third_name_ + " " + last_name_;
    if (!second_name_.empty())
        return first_name_ + " " + second_name_ + " " + last_name_;
    return first_name_ + " " + last_name_;
}

bool model::Name::IsBeforeBySurname(const model::Name &other) const {
    for (int i = 0; i < other.Surname().size() && i < last_name_.size(); ++i) {
        if (other.Surname()[i] < last_name_[i]) {
            return false;
        } else if (other.Surname()[i] > last_name_[i]) {
            return true;
        }
    }
    return false;
}

bool model::Name::IsBeforeByFirstName(const model::Name &other) const {
    for (int i = 0; i < other.FirstName().size() && i < last_name_.size(); ++i) {
        if (other.FirstName()[i] < last_name_[i]) {
            return false;
        } else if (other.FirstName()[i] > last_name_[i]) {
            return true;
        }
    }
    return false;
}
