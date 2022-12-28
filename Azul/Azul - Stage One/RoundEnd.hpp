#include <cstdlib>
#include <iostream>
#include <time.h>
#include <algorithm>
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

void endRound(std::vector<playerBoard>* boards, 
              std::vector<int>* scores)

- Checks the rows and fills in the position on the board
  corresponding to any filled rows found. Uses mod to
  to determine board location

******************************************************/

void endRound(std::vector<playerBoard>* boards, std::vector<int>* scores){

    //for each player
    for (int i = 0; i < boards->size(); i++){

        //for each step
        for (int j = 0; j < 5; j++){

            //if row is full, fill board position and add points as well as clearing the step
            if (std::adjacent_find(boards->at(i).steps.at(j).begin(), boards->at(i).steps.at(j).end(), std::not_equal_to<>()) == boards->at(i).steps.at(j).end() && !std::count(boards->at(i).steps.at(j).begin(), boards->at(i).steps.at(j).end(), -1)){

                //get tile
                int value = boards->at(i).steps.at(j).at(0);

                //get real position
                int realpos = (value + j) % 5;

                //set board pos
                boards->at(i).board.at(j).at(realpos) = value;

                //update score
                //(just teaching it first that filling a row and placing the tile on the board is good)
                //HOWEVER points for harder to fill rows are higher (Teach it filling harder rows quickly is better)
                scores->at(i) += j;

                //reset all elements
                for (int k = 0; k < boards->at(i).steps.at(j).size(); k++) 
                    boards->at(i).steps.at(j).at(k) = -1;
            }
        }

        //check minus rows
        //(just teaching it first that the minus row is bad [AKA fill rows without minus rows])

        for(int j = 0; j < 5; j++){
            if (boards->at(i).lossRow.at(j) != -1){
                scores->at(i) -= 1;
                boards->at(i).lossRow.at(j) = -1;
            }
        }

    }

}