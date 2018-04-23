//
// Created by adrja on 21.04.2018.
//

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "Zipper.h"

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::pair;
using std::literals::string_literals::operator ""s;

int foo(const vector<string> &v1, const vector<int> &v2) {
    for (const pair<string, int> &p : Zipper::zip(v1, v2)) {
        if (p.first == "elo") {
            return p.second + 4;
        }
    }
    return 0;
}


int main() {
    vector<int> vi = {1, 2, 3};
    vector<string> vs = {"one"s, "two"s, "three"s};

    //PROSTY przykład
    for (const auto i : vi) {
        cout << i;
    }
    cout << endl;
    //to samo bez auto:
    for (const int i : vi) {
        cout << i;
    }
    cout << endl;
    //przetłumaczony powyższa petla mniej wiecej tak jak to kompilator
    //rozumie:
    for (vector<int>::iterator it = vi.begin(); it != vi.end(); ++it) {
        const int i = *it;
        cout << i;
    }
    cout << endl;

    //Przykład z zipperem
    for (const auto &p : Zipper::zip(vs, vi)) {
        cout << p.second << " is " << p.first;
    }
    cout << endl;
    //to samo bez auto:
    for (const pair<string, int> &p : Zipper::zip(vs, vi)) {
        cout << p.second << " is " << p.first;
    }
    cout << endl;

    //przetłumaczony powyższa petla mniej wiecej tak jak to kompilator
    //rozumie:
    Zipper tmp = Zipper::zip(vs, vi);
    for (ZipperIterator it = tmp.begin(); it != tmp.end(); ++it) {
        const pair<string, int> &p = *it;
        cout << p.second << " is " << p.first;
    }
    cout << endl;

}