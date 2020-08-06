#include<vector>
#include<map>
using namespace std;

#ifndef UTIL_H
#define UTIL_H


#define NUM_PLACES 20

void move(int x, int& curPos); //move player on map by value x

bool specialExecution(Task task, int& curPos, Player*& p, bool& pOut); //performs tasks when player steps on a "special place"

void createMap(Place* map[]); //creates map

void destroyMap(Place* map[]); //destroys map

vector<int> createPlayers(Player* players[], int numPlayers, map<string,int>& name_index); //creates players, returns current location of players

void destroyPlayers(Player* players[], int numPlayers); // destroys players
 
void printMap(Place** map, int pos1, int pos2); //prints map when 2 players are playing

void printMap(Place** map, int pos1, int pos2, int pos3); //prints map when 3 players are playing

void printMap(Place** map, int pos1, int pos2, int pos3, int pos4); //prints map when 4 players are playing

void printMapHandler(Place** map, vector<int> locations); //calls the right printMap function

int roll(); // returns random number as player rolls a die

void choseNumPlayers(int& numPlayers); //promts user to enter number of players

void welcomeMessage(); 

bool gameOverF(Player* winner); //displays stats of the winner and returns gameOver=true

bool playerOut(int indx, int& numPlayers, Player* players[], Place* map[]); //destroys player when out of money


#endif
