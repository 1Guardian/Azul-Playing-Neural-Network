#include <cstdlib>
#include <iostream>
#include <time.h>
#include <algorithm>
#include <vector>
#include "Boards.h"


/*****************************************************

void chooseStepsLoction(playerBoard* current, int item, int count)

- lets the player choose which steps location the tile will
  be placed in. If the location has an overflow, the remaining
  tiles go into the minus score area. if the row is already
  in use for another tile type, the action is rejected.

******************************************************/

void chooseStepsLoction(playerBoard* current, int item, int count){
    current->printBoard();
    current->printSteps();
    current->printLoss();

    int row = -1;
    bool safeChoice = false;


    //get the row to place it in, and make sure it is a valid move
    while(!safeChoice){

        safeChoice = true;

        std::cout << "Which row of your steps would you like to place your tile in: " << std::endl;
        std::cin >> row;

        if (row > 0 && row < 6){
            for (int i = 0; i < row; i++){
                if (current->steps.at(row-1).at(i) != -1 && current->steps.at(row-1).at(i) != item)
                    safeChoice = false;
            }
        }
        else {
            safeChoice = false;
        }
    }

    //if valid, place in row and place extra in the loss row
    for (int i = 0; i < row; i++){
        if (current->steps.at(row-1).at(i) == -1 && count > 0){
            current->steps.at(row-1).at(i) = item;
            count -= 1;
        }
    }
    for (int i = 0; i < current->lossRow.size(); i++){
        if (current->lossRow.at(i) == -1 && count > 0){
            current->lossRow.at(i) = item;
            count -= 1;
        }
            
            
    }
}

/*****************************************************

int updateFactories(std::vector<std::vector<int>>* circles, 
                    std::vector<int>* pot, int selection, 
                    int item)

- updates the factories and the pot based on which item
  was selected. If the item is already in the pot then it 
  erases that item from the pot. returns the number of items
  found from the selection that the player will be using.
  
******************************************************/

int updateFactories(std::vector<std::vector<int>>* circles, std::vector<int>* pot, int selection, int item){

    //count of items found
    int found = 0;

    //taking from pot
    if (selection == 10){
        int start = -1;
        int end = -1;
        for (int i = 0; i < pot->size(); i++){  
            
            //get the range of the items from the pot
            if (pot->at(i) == item){
                if (start == -1){
                    start = i;
                }
                else {
                    if (i == pot->size()-1){
                        end = i;
                    }
                    else if (pot->at(i+1) != item){
                        end = i;
                    }
                }
            }
        }

        //remove the items from the pot
        pot->erase(pot->begin() + start, pot->begin() + end);
        found = end - item;
    }

    //taking from a factory
    else{
        //retreive item from factory and all duplicates
        for (int i = 3; i > -1; i--){  

            //add to player
            if (circles->at(selection).at(i) == item){
                found += 1;
            }

            //add to pot
            else{
                pot->push_back(circles->at(selection).at(i));
                
            }
        }
        circles->at(selection).clear();
    }

    
    return found;
}

/*****************************************************

void selectFactory(std::vector<std::vector<int>>* circles, 
                   std::vector<int>* pot, 
                   playerBoard* current)

- Prompts user to select factory or pot and then 
  hands control over to preceeding functions to 
  handle the turn.
  
******************************************************/
void selectFactory(std::vector<std::vector<int>>* circles, std::vector<int>* pot, playerBoard* current){

    bool selected = false;
    int selection = -1;
    int item = -1;

    //choose factory
    while(!selected){
        std::cout << "\nSelect Factory (pot is 10): " << std::endl;
        std::cin >> selection;

        if (selection != 10){
            (circles->at(selection).size() > 0) ? std::cout << "" : std::cout << "\nCannot Select Empty Factory!\n";
            (circles->at(selection).size() > 0) ? selected = true : selected = false;
        }
        else {
            (pot->size() > 0) ? std::cout << "" : std::cout << "\nCannot Select Empty Pot!\n";
            (pot->size() > 0) ? selected = true : selected = false;
        }

    }

    //choose tile
    selected = false;
    while(!selected){
        std::cout << "Select Item in Factory: " << std::endl;
        std::cin >> item;

        (item > 0 && item < 5) ? std::cout << "" : std::cout << "\nSelection must be between 0 and 5\n";
        (item > 0 && item < 5) ? selected = true : selected = false;
    }

    //make sure pot is sorted
    std::sort(pot->begin(), pot->end());

    //get count of item and update the factories
    int itemSelected = circles->at(selection).at(item-1);
    std::cout << "Item selected: " << itemSelected << std::endl;
    
    //choose where to place it on the board
    chooseStepsLoction(current, itemSelected, updateFactories(circles, pot, selection, itemSelected));

}