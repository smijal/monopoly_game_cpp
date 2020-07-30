#include<vector>
using namespace std;

#ifndef UTIL_H
#define UTIL_H


#define NUM_PLACES 20

void move(int x, int& curPos);

void specialExecution(Task task, int& curPos);

void createMap(Place** map);

vector<int> createPlayers(Player** players, int numPlayers);

void printMap(Place** map, int pos1, int pos2);

void printMap(Place** map, int pos1, int pos2, int pos3);

void printMap(Place** map, int pos1, int pos2, int pos3, int pos4);

void printMapHandler(Place** map, vector<int> locations);

int roll();

void choseNumPlayers(int& numPlayers);

void welcomeMessage();

#endif
