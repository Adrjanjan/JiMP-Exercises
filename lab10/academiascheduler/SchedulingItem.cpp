//
// Created by adrja on 24/05/2018.
//

#include "SchedulingItem.h"

academia::SchedulingItem::SchedulingItem(int course, int teacher, int room, int time_slot, int year) {
    course_id = course;
    teacher_id = teacher;
    room_id_ = room;
    time_slot_ = time_slot;
    year_ = year;
}

int academia::SchedulingItem::CourseId() const {
    return course_id;
}

int academia::SchedulingItem::TeacherId() const {
    return teacher_id;
}

int academia::SchedulingItem::RoomId() const {
    return room_id_;
}

int academia::SchedulingItem::TimeSlot() const {
    return time_slot_;
}

int academia::SchedulingItem::Year() const {
    return year_;
}
