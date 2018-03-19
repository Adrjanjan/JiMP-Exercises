//
// Created by adrja on 19.03.2018.
//


#include "Lab_03.h"


int main() {

    {
        std::array<Punkt3D, 10> a_punkty;
        double min = INTMAX_MAX, max = 0;
        Punkt3D punkt_min = Punkt3D(INTMAX_MAX, INTMAX_MAX, INTMAX_MAX, "min"), punkt_max = Punkt3D(0, 0, 0, "max");

        for (auto &pkt : a_punkty) {
            pkt.setVal(random() % 100, random() % 100, random() % 100);
            pkt.setIdent(std::to_string());

            if (pkt.getOdleglosc0() > max) {
                max = pkt.getOdleglosc0();
                punkt_max = pkt;

            }
            if (pkt.getOdleglosc0() < min) {
                min = pkt.getOdleglosc0();
                punkt_min = pkt;
            }
        }

        std::cout << "Odległość punktu " << punkt_max.getIdent() << " od początku układu współrzędnych wynosi "
                  << punkt_max.getOdleglosc0() << std::endl;
        std::cout << "Odległość punktu " << punkt_min.getIdent() << " od początku układu współrzędnych wynosi "
                  << punkt_min.getOdleglosc0() << std::endl;

        Punkt3D punkt3;
        punkt3 = punkt_max + punkt_min;
        std::cout << "Odległość punktu " << punkt3.getIdent() << " od początku układu współrzędnych wynosi "
                  << punkt3.getOdleglosc0() << std::endl;

    }

//    {
//        Zespolona a = Zespolona(3, 4, "a");
//        Zespolona b = Zespolona(3, 2, "b");
//
//        a.print();
//        std::cout<<a.Modul()<<std::endl;
//        a += b;
//        a.print();
//        b.print();
//        std::cout<<a.Modul()<<std::endl;
//
//    }


    return 0;
}