#include<vector>
using namespace std;

#ifndef UTIL_H
#define UTIL_H


#define NUM_PLACES 20

void move(int x, int& curPos);

bool specialExecution(Task task, int& curPos, Player*& p, bool& pOut);

void createMap(Place* map[]);

void destroyMap(Place* map[]);

vector<int> createPlayers(Player* players[], int numPlayers);

void destroyPlayers(Player* players[], int numPlayers);

void printMap(Place** map, int pos1, int pos2);

void printMap(Place** map, int pos1, int pos2, int pos3);

void printMap(Place** map, int pos1, int pos2, int pos3, int pos4);

void printMapHandler(Place** map, vector<int> locations);

int roll();

void choseNumPlayers(int& numPlayers);

void welcomeMessage();

bool gameOverF(Player* winner);

bool playerOut(int indx, int& numPlayers, Player* players[], Place* map[]);


#endif
