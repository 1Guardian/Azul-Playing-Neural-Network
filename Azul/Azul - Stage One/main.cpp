#include "Generators.hpp"
#include "Display.hpp"
#include "MakeActions.hpp"
#include "RoundEnd.hpp"

int main(){

    std::vector<int> availableTiles(0,0);
    std::vector<std::vector<int>> circles(9);
    std::vector<int> pot;
    int playerCount = 3;
    std::vector<playerBoard> players(playerCount);
    std::vector<int> score(playerCount);
    
    //set up the game
    generateTiles(&availableTiles, &circles, playerCount);

    //run through one round 
    for (int i = 0; i < playerCount; i++){

        //each turn
        printFactories(&circles, &pot);
        printPlayer(players.at(i), i);

        selectFactory(&circles, &pot, &players.at(i));
        printPlayer(players.at(i), i);
    }

    //end round
    endRound(&players, &score);

    //print finals
    for (int i = 0; i < playerCount; i++)
        printPlayer(players.at(i), i);

    return 1;
}