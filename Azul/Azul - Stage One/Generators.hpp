#include <cstdlib>
#include <iostream>
#include <time.h>
#include <vector>

/******************************************

Tiles:

0 = azul
1 = yellow
2 = red
3 = black
4 = white

*******************************************/

/*****************************************************

void refillBag(std::vector<int>* availableTiles, 
               std::vector<std::vector<int>>* circles)

- Refills the bag. Checks for which tiles are already
  in use and ignores them in the refilling process

******************************************************/

void refillBag(std::vector<int>* availableTiles, std::vector<std::vector<int>>* circles){

    //vector for storing counts
    std::vector<int> counts(5, 0);

    //figure out which tiles are in play
    for (int j =0; j < 9; j++){
        for (int i = 0; i < circles->at(j).size(); i++){
            counts.at(circles->at(j).at(i)) += 1;
        }
    }

    //refill the bag
    for (int j = 0; j < 5; j++){
        for (int i = 0; i < 20 - counts.at(j); i++){
            availableTiles->push_back(j);
        }
    }

    return;
}

/*****************************************************

void generateTiles(std::vector<int>* availableTiles, 
                   std::vector<std::vector<int>>* circles, 
                   int playerCount)

- Fills the 'circles' vectors with tiles to be used in the
  game. Keeps track of tiles that are already used so that
  when the tiles need to be refilled, they can be easily.
  will call the refillBag function when out of tiles.

******************************************************/

void generateTiles(std::vector<int>* availableTiles, std::vector<std::vector<int>>* circles, int playerCount){

    //rand
    srand(time(0));

    //setup generators depending on player amount
    switch (playerCount){
        case 2: // 5 factories
            for (int j = 0; j < 5; j++){
                for (int i = 0; i < 4; i++){

                    //refill bag if needed
                    if (availableTiles->size() < 1) refillBag(availableTiles, circles);
                    
                    //add tile to factory
                    int index = rand() % availableTiles->size();
                    circles->at(j).push_back(availableTiles->at(index));
                    availableTiles->erase(availableTiles->begin()+index);
                }
            }
            break;

        case 3: // 7 factories 
            for (int j = 0; j < 7; j++){
                for (int i = 0; i < 4; i++){

                    //refill bag if needed
                    if (availableTiles->size() < 1) refillBag(availableTiles, circles);
                    
                    //add tile to factory
                    int index = rand() % availableTiles->size();
                    circles->at(j).push_back(availableTiles->at(index));
                    availableTiles->erase(availableTiles->begin()+index);
                }
            }
            break;

        case 4: // 9 factories
            for (int j = 0; j < 9; j++){
                for (int i = 0; i < 4; i++){

                    //refill bag if needed
                    if (availableTiles->size() < 1) refillBag(availableTiles, circles);
                    
                    //add tile to factory
                    int index = rand() % availableTiles->size();
                    circles->at(j).push_back(availableTiles->at(index));
                    availableTiles->erase(availableTiles->begin()+index);
                }
            }
            break;

        default:
            break;
    }

}