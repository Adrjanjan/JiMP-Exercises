//
// Created by adrja on 24/05/2018.
//

#ifndef JIMP_EXERCISES_SCHEDULINGITEM_H
#define JIMP_EXERCISES_SCHEDULINGITEM_H


namespace academia {
    class SchedulingItem {
    public:
        SchedulingItem(int, int, int, int, int);

        int CourseId() const;

        int TeacherId() const;

        int RoomId() const;

        int TimeSlot() const;

        int Year() const;

    private:
        int course_id;  // - identyfikator kursu
        int teacher_id; //- identyfikator nauczyciela akademickiego prowadzącego te zajęcia o tej godzinie
        int room_id_;   // - identyfikator pomieszczenia w którym odbywają się zajęcia
        int time_slot_; //- okno czasowe, w którym odbywają się zajęcia, dla uproszczenia cały tydzień jest podzielony na N okien czasowych nie zachodzących na siebie (np. dla 20: 1 ⇒ pon 8:00-10:00, 2 ⇒ pon 10:00-12:00, … 20 ⇒ pią 14:00-16:00). Zajęcia wymagają zawsze pojedynczego okna czasowego i zawsze są z nim wyrównane tzn. nie mogą zajmować połowę 12ego i połowę 13ego
        int year_;      //- rok studiów na którym obowiązuje przedmiot
    };
}


#endif //JIMP_EXERCISES_SCHEDULINGITEM_H
