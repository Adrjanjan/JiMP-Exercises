//
// Created by adrja on 19.03.2018.
//

#ifndef JIMP_EXERCISES_LAB_03_H
#define JIMP_EXERCISES_LAB_03_H

#include <iostream>
#include <cmath>
#include <array>
#include <random>
#include <string>

class Punkt3D {
    double x, y, z;
    std::string ident;
public:
    Punkt3D();

    Punkt3D(double a, double b, double c, std::string id);

    ~Punkt3D();

    double getOdleglosc0();

    void setVal(double a, double b, double c);

    std::string getIdent();

    void setIdent(std::string id);

    Punkt3D operator+(const Punkt3D &p);

    void DelPunkt3D();
};

class Zespolona {
    double x, y;
    std::string id;
public:
    Zespolona(double a, double b, std::string name);

    double Modul();

    Zespolona operator+(const Zespolona &a);

    Zespolona operator+=(const Zespolona &a);

    void print();
};

//////////////////////////////////////////////////
/////////////////////////////////////////////////

class Triangle {
    double a, b, c;
    double wspolrzedne[3][2]{};
    std::string id;
public:
    Triangle();

    Triangle(double _a, double _b, double _c, std::string name);

    Triangle(double **wsp, std::string name);

    double Pole();

    void setValues(double _a, double _b, double _c, std::string name);

    std::string getName();
};
//////////////////////////////////////////////////
/////////////////////////////////////////////////

class Ostroslup {
    double p_podstawy, wysokosc;
    std::string id;
public:
    Ostroslup();

    Ostroslup(double pole_podstawy, double wysokosc_ostr, std::string name);

    double Objetosc();

    void setValues(double pole_podstawy, double wysokosc_ostroslupa, std::string name);

    std::string getName();
};

////napisz program z klasą do opisu danych o samochodach różnych typów

class Car {
    double pojemnosc_silnika;
    int data_produkcji;
    std::string marka;
    std::string model;
    bool bezwypadkowy;
public:
    Car();

    Car(std::string _marka, std::string _model, int _data_produkcji, double _pojemnosc_silnika, bool _bezwypadkowy);

};


#endif //JIMP_EXERCISES_LAB_03_H
