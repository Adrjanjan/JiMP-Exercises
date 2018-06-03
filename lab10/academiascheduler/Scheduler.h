//
// Created by adrja on 23/05/2018.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

#include <vector>
#include <map>
#include <set>

#include "Schedule.h"


namespace academia {
    class Scheduler {
    public:
        virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms,
                                            const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                            const std::map<int, std::set<int>> &courses_of_year,
                                            int n_time_slots) = 0;
    };

    class GreedyScheduler : public Scheduler {
    public:
        Schedule PrepareNewSchedule(const std::vector<int> &rooms,
                                    const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                    const std::map<int, std::set<int>> &courses_of_year,
                                    int n_time_slots) override;
    };

    class NoViableSolutionFound : public std::logic_error {
    public:
        NoViableSolutionFound(const std::string &message) : logic_error(message) {};
    };
}

#endif //JIMP_EXERCISES_SCHEDULER_H
