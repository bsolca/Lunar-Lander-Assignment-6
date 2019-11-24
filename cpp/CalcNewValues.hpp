//
// Created by Shadow on 22/11/2019.
//

#ifndef ASSIGNMENT6_CALCNEWVALUES_HPP
#define ASSIGNMENT6_CALCNEWVALUES_HPP

#include <string>
#include <iostream>
#include <sstream>

class CalcNewValues {
private:
    int const GRAVITY;
    int altitude;
    int fuel;
    int velocity;
    int time;
    void printParam();
    void readLines();

public:
    CalcNewValues();

};


#endif //ASSIGNMENT6_CALC_NEW_VALUES_HPP
