#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "Gen.h"
#include "LifeHistory.h"

// Function to parse string type into integer
int strtoint(std::string str) {
    int cont = 0, res = 0;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] >= '0' && str[i] <= '9') {
            res += (str[i] - '0') * pow(10, cont);
            cont++;
        }
    }

    return res;
}

//  Function that returns the lenght of an array
int index(std::string text, char pattern) {
    int cont = 0;
    for (int i = 0; i < text.length(); ++i) {
        if (text[i] == pattern) {
            cont++;
        }
    }
    return cont;
}

// Initial configuration of the game settings, it reads the bg.txt file where the parameters of generation are stored
Gen initConfig(std::string text) {
    std::string::size_type sz;
    std::string myText;
    std::ifstream file(text);
    getline(file, myText);
    int size = strtoint(myText);

    Gen generation(size);
    while (getline(file, myText)) {
        generation.setCell(
                strtoint(myText.substr(0, index(myText, ';'))),
                strtoint(myText.substr(index(myText, ';') + 1, myText.length())),
                true
        );
    }

    file.close();
    return generation;
}


int main(int argc, char **argv) {

    LifeHistory life(initConfig("bg.txt"));

    life.getCurrent().show();
    std::cout << std::endl;
    std::cout << std::endl;
    life.evolve();
    life.getCurrent().show();


    return 0;
}
