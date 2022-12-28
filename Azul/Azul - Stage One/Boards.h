#include <cstdlib>
#include <iostream>
#include <time.h>
#include <vector>

#ifndef BOARDS_H
#define BOARDS_H

struct playerBoard{

    std::vector<std::vector<int>> steps;
    std::vector<std::vector<int>> board;
    std::vector<int> lossRow;

    playerBoard(){
        for (int i = 0; i < 5; i++){
            std::vector<int> temp;
            board.push_back(temp);
            steps.push_back(temp);
            for (int j =0; j < 5; j++){
                board.at(i).push_back(-1);
            }
            for (int j =0; j < i+1; j++){
                steps.at(i).push_back(-1);
            }
            lossRow.push_back(-1);
        }
    }

    void printSteps(){

        std::cout << "Steps:\n";

        for (int i = 0; i < 5; i++){
            for (int j =0; j < i+1; j++){
                std::cout << steps.at(i).at(j) << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    void printBoard(){

        std::cout << "Board:\n";

        for (int i = 0; i < 5; i++){
            for (int j =0; j < 5; j++){
                std::cout << board.at(i).at(j) << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    void printLoss(){

        std::cout << "Loss:\n";

        for (int i = 0; i < 5; i++){
            std::cout << lossRow.at(i) << " ";
        }
        std::cout << std::endl;
    }
};

#endif