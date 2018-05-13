

//
// Created by suchalek on 18.04.18.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORYQUERIES_H
#define JIMP_EXERCISES_STUDENTREPOSITORYQUERIES_H

#include <utility>
#include <vector>
#include <memory>
#include "Student.h"

namespace academia {

    class Query {
    public:
        virtual bool Accept(const Student &student) const = 0;
    };

    class ByFirstName : public Query {
    public:
        ByFirstName(std::string first_name) : first_name_(std::move(first_name)) {};

        bool Accept(const Student &student) const override;

    private:
        std::string first_name_;
    };

    class ByLastName : public Query {
    public:
        ByLastName(std::string last_name) : last_name_(std::move(last_name)) {};

        bool Accept(const Student &student) const override;

    private:
        std::string last_name_;
    };

    class ByOneOfPrograms : public Query {
    public:
        ByOneOfPrograms(std::vector<std::string> programs) : programs_(std::move(programs)) {};

        bool Accept(const Student &student) const override;

    private:
        std::vector<std::string> programs_;
    };

    class ByYearLowerOrEqualTo : public Query {
    public:
        ByYearLowerOrEqualTo(StudyYear year) : year_(year) {};

        bool Accept(const Student &student) const override;

    private:
        StudyYear year_;
    };

    class OrQuery : public Query {
    public:
        OrQuery(std::unique_ptr<Query> left, std::unique_ptr<Query> right);

        bool Accept(const Student &student) const override;

    private:
        std::unique_ptr<Query> left_;
        std::unique_ptr<Query> right_;
    };

    class AndQuery : public Query {
    public:
        AndQuery(std::unique_ptr<Query> left, std::unique_ptr<Query> right);

        bool Accept(const Student &student) const override;

    private:
        std::unique_ptr<Query> left_;
        std::unique_ptr<Query> right_;
    };
}


#endif //JIMP_EXERCISES_STUDENTREPOSITORYQUERIES_H