#include <cstdlib>
#include <iostream>
#include <time.h>
#include <vector>
#include "Boards.h"

/******************************************

Tiles:

0 = azul
1 = yellow
2 = red
3 = black
4 = white

*******************************************/

/*****************************************************

void printFactories(std::vector<std::vector<int>>* circles,
                    std::vector<int>* pot)

- Prints factories. That's it.

******************************************************/

void printFactories(std::vector<std::vector<int>>* circles, std::vector<int>* pot){
    for (int i = 0; i < 9; i++){
        if (circles->at(i).size() > 0){

            std::cout << "Factory " << i << ": ";
            
            for (int j = 0; j < circles->at(i).size(); j++){
                std::cout << circles->at(i).at(j) << "  ";
            }

            std::cout << std::endl;
        }
    }
    if (pot->size() > 0){

        std::cout << "Pot:" << std::endl;
        
        for (int j = 0; j < pot->size(); j++){
            std::cout << pot->at(j) << "  ";
        }

        std::cout << std::endl;
    }
}

/*****************************************************

void printPlayer(playerBoard current, int num)

- Prints players. That's it.

******************************************************/

void printPlayer(playerBoard current, int num = 0){
    std::cout << std::endl << "Player " << num << ":" << std::endl;
    std::cout << std::endl;
    current.printBoard();
    current.printSteps();
    current.printLoss();
}