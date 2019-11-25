//
// Created by Shadow on 22/11/2019.
//

#include "CalcNewValues.hpp"

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
        if (!inputLine.rfind('#', 0)) {
            //This is a status line of text, and
            //should be passed down the pipeline
            std::cout << inputLine << std::endl;
        } else if (!inputLine.rfind('%', 0)) {
            //This is an input burn rate
            int burnRate = stringToInt(inputLine);
            if (this->altitude <= 0) {
                std::cout << "#The game is over." << std::endl;
            } else if (burnRate > this->fuel) {
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
                printParam();
            }
        }
    } while (std::getline(std::cin, inputLine) && altitude);
}

int CalcNewValues::stringToInt(std::string str) {
    for (int i = 0; i < str.length(); i++) {
        if (!isdigit(str.at(i))) {
            str.erase(i, 1);
            i--;
        }
    }
    return std::atoi(str.c_str());
}
