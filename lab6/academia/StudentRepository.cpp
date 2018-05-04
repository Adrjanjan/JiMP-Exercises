//
// Created by adrja on 21.04.2018.
//

#include "StudentRepository.h"

academia::StudentRepository::StudentRepository() = default;

size_t academia::StudentRepository::StudentCount() {
    return students_.size();
}

academia::Student &academia::StudentRepository::operator[](std::string student_id) {
    for (auto &s: students_) {
        if (s.Id() == student_id) {
            return s;
        }
    }

    // powinno być throw exception, ale jeszcze nie było tego
}

bool academia::operator==(const academia::StudentRepository &l, const academia::StudentRepository &r) {
    bool found = true;

    for (const auto &i: l.students_) {
        found = false;
        for (const auto &j: r.students_) {
            if (i == j) {
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}

std::vector<academia::Student> academia::StudentRepository::FindByQuery(std::unique_ptr<academia::Query> query) {
    std::vector<academia::Student> tmp;
    for (auto stud : students_) {
        if (query->Accept(stud)) {
            tmp.emplace_back(stud);
        }
    }
    return std::move(tmp);
}
