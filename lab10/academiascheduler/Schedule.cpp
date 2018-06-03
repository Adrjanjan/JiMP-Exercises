//
// Created by adrja on 24/05/2018.
//


#include <numeric>
#include "Schedule.h"

void academia::Schedule::InsertScheduleItem(academia::SchedulingItem to_insert) {
    schedule_.push_back(to_insert);
}

academia::Schedule academia::Schedule::OfTeacher(int teacher_id) const {
    std::vector<academia::SchedulingItem> matching_teachers;
    matching_teachers.clear();
    std::copy_if(schedule_.begin(), schedule_.end(), std::inserter(matching_teachers, matching_teachers.begin()),
                 [teacher_id](auto item) { return item.TeacherId() == teacher_id; });

    return Schedule(matching_teachers);
}

academia::Schedule academia::Schedule::OfRoom(int room_id) const {
    std::vector<academia::SchedulingItem> matching_room;
    matching_room.clear();
    std::copy_if(schedule_.begin(), schedule_.end(), std::inserter(matching_room, matching_room.begin()),
                 [room_id](academia::SchedulingItem item) { return item.RoomId() == room_id; });
    return Schedule(matching_room);
}

academia::Schedule academia::Schedule::OfYear(int year) const {
    std::vector<academia::SchedulingItem> matching_year;
    matching_year.clear();
    std::copy_if(schedule_.begin(), schedule_.end(), std::inserter(matching_year, matching_year.begin()),
                 [year](academia::SchedulingItem item) { return item.Year() == year; });
    return Schedule(matching_year);
}

std::vector<int> academia::Schedule::AvailableTimeSlots(int upper_limit) {
    std::vector<bool> available(static_cast<unsigned long>(upper_limit), true);
    std::vector<int> available_int;
    std::iota(available.begin(), available.end(), 1);
    for (auto item : schedule_) {
        available[item.TimeSlot() - 1] = false;
    }

    for (int i = 0; i < available.size(); ++i) {
        if (available[i]) {
            available_int.emplace_back(i + 1);
        }
    }
    return available_int;
}

size_t academia::Schedule::Size() const {
    return schedule_.size();
}

academia::SchedulingItem academia::Schedule::operator[](int id) const {
    return schedule_[id];
}

academia::SchedulingItem &academia::Schedule::operator[](int id) {
    return schedule_[id];
}

academia::Schedule::Schedule(const std::vector<academia::SchedulingItem> &schedule) : schedule_(schedule) {}
