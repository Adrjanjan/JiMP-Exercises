//
// Created by adrja on 19.03.2018.
//

#include "Lab_03.h"

Punkt3D::Punkt3D(){
    x=1.0;
    y=1.0;
    z=1.0;

    ident = "Punkt";
}

Punkt3D::Punkt3D(double a, double b, double c, std::string id){
    x=a;
    y=b;
    z=c;
    ident = id;
};

void Punkt3D::setVal(double a, double b, double c){
    x=a;
    y=b;
    z=c;
}

double Punkt3D::getOdleglosc0(){
    return sqrt(x*x+y*y+z*z);
}

std::string Punkt3D::getIdent(){
    return ident;
}

void Punkt3D::setIdent(std::string id){
    ident = id;
}

Punkt3D Punkt3D::operator+(const Punkt3D & p){
    Punkt3D pWy;
    pWy.x = x + p.x;
    pWy.y = y + p.y;
    pWy.z = z + p.z;
    pWy.ident = ident + "+" + p.ident;
    return pWy;
}

void Punkt3D::DelPunkt3D(){
    delete this;
}

Punkt3D::~Punkt3D(){
    std::cout<<ident<<std::endl;
}

//////////////////////////////////////////////////
/////////////////////////////////////////////////

Zespolona::Zespolona(double a, double b, std::string name){
    x=a;
    y=b;
    id = name;
}

double Zespolona::Modul(){
    return sqrt(x*x + y*y);
}

Zespolona Zespolona::operator+(const Zespolona &a){
    return Zespolona(x+a.x, y+a.y, id+"+"+a.id);
}

Zespolona Zespolona::operator+=(const Zespolona &a){
    x+=a.x, y+=a.y, id+= "+"+a.id;
    return *this;
}

void Zespolona::print(){
    if (y>0) std::cout<<id<<"= "<< x <<" + "<<y<<"i \n";
    else std::cout<<id<<"= "<< x <<" "<<y<<"i \n";
}

//////////////////////////////////////////////////
/////////////////////////////////////////////////

Triangle::Triangle(double _a, double _b, double _c, std::string name){
    a=_a;
    b=_b;
    c=_c;
    id = name;
}

Triangle::Triangle(double **wsp, std::string name){
    id = name;
    for(int i =0; i<3;++i){
        for(int j =2; j<2; ++j){
            wspolrzedne[i][j] = wsp[i][j];
        }
    }
}

double Triangle::Pole(){
    double p = 0.5*(a + b + c);
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

void Triangle::setValues(double _a, double _b, double _c, std::string name){
    a=_a;
    b=_b;
    c=_c;
    id = name;
}

std::string Triangle::getName(){
    return id;
}

//////////////////////////////////////////////////
/////////////////////////////////////////////////

Ostroslup::Ostroslup(double pole_podstawy, double wysokosc_ostr, std::string name){
    p_podstawy = pole_podstawy;
    wysokosc = wysokosc_ostr;
    id = name;
}

double Ostroslup::Objetosc(){
    return 1/3*(p_podstawy * wysokosc);
}

void Ostroslup::setValues(double pole_podstawy, double wysokosc_ostroslupa, std::string name){
    p_podstawy = pole_podstawy;
    wysokosc = wysokosc_ostroslupa;
    id = name;
}

std::string Ostroslup::getName(){
    return id;
}