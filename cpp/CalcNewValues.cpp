//
// Created by Shadow on 22/11/2019.
//

#include "CalcNewValues.hpp"

#include <iostream>

int main() {
    new CalcNewValues;
    return 0;
}

CalcNewValues::CalcNewValues() : GRAVITY(2),
                                 altitude(1000),
                                 fuel(500),
                                 velocity(70),
                                 time(0) {
    printParam();
    readLines();
}

void CalcNewValues::printParam() {
    std::cout << "%a" << altitude << std::endl;
    std::cout << "%f" << fuel << std::endl;
    std::cout << "%v" << velocity << std::endl;
    std::cout << "%t" << time << std::endl;
}

void CalcNewValues::readLines() {
    std::string inputLine;

    do {
        if (inputLine.length() > 0) {
            if (inputLine.at(0) == '#') {
                //This is a status line of text, and
                //should be passed down the pipeline
                std::cout << inputLine << std::endl;
            } else if (inputLine.at(0) == '%') {
                //This is an input burn rate
                inputLine.erase(0);
                std::cout << "on as@ " << inputLine << std::endl;
                int burnRate = std::stoi(inputLine.erase(0));
                if (altitude <= 0) {
                    std::cout << "#The game is over." << std::endl;
                } else if (burnRate > fuel) {
                    std::cout << "#Sorry, you don't have that much fuel." << std::endl;
                } else {
                    //Calculate new application state
                    time = time + 1;
                    altitude = altitude - velocity;
                    velocity = ((velocity + GRAVITY) * 10 -
                                burnRate * 2) / 10;
                    fuel = fuel - burnRate;
                    if (altitude <= 0) {
                        altitude = 0;
                        if (velocity <= 5) {
                            std::cout << "#You have landed safely." << std::endl;
                        } else {
                            std::cout << "#You have crashed." << std::endl;
                        }
                    }
                }
                //Print new values
                this->printParam();
            }
        }
    } while ((std::getline(std::cin, inputLine)) && (altitude > 0));
}
