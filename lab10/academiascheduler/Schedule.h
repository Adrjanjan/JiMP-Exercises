//
// Created by adrja on 24/05/2018.
//

#ifndef JIMP_EXERCISES_SCHEDULE_H
#define JIMP_EXERCISES_SCHEDULE_H

#include <vector>
#include <algorithm>
#include <cstddef>
#include "SchedulingItem.h"


namespace academia {

    class Schedule {
    public:
        Schedule() = default;

        explicit Schedule(const std::vector<SchedulingItem> &items);

        void InsertScheduleItem(SchedulingItem to_insert);

        Schedule OfTeacher(int) const;

        Schedule OfRoom(int) const;

        Schedule OfYear(int) const;

        std::vector<int> AvailableTimeSlots(int);

        size_t Size() const;

        SchedulingItem operator[](int id) const;

        SchedulingItem &operator[](int id);

    private:
        std::vector<academia::SchedulingItem> schedule_;
    };
}

#endif //JIMP_EXERCISES_SCHEDULE_H
