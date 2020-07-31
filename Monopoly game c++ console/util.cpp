#include<iostream>
#include "place.h"
#include "city.h"
#include "special.h"
#include "player.h"
#include "util.h"
#include<algorithm>
#include<windows.h>
#include<vector>

using namespace std;

//enum Task {Forward_3_places, Forward_5_places, Back_3_places, Back_5_places, Your_turn, Jail, Start};

void move(int x, int& curPos){
	curPos+=x;
	curPos%=NUM_PLACES;
}

void specialExecution(Task task, int& curPos){
	switch(task){
		case Forward_3_places: move(3,curPos); cout<<"\n  You moved forward 3 places..."; break;
		case Forward_5_places: move(5, curPos);cout<<"\n  You moved forward 5 places..."; break;
		case Back_3_places: move(-3,curPos);cout<<"\n  You moved back 3 places..."; break;
		case Back_5_places: move(-5,curPos);cout<<"\n  You moved back 5 places..."; break;
		case Jail: curPos=7; cout<<"\n  You are in Jail"; break;
		case Your_turn: cout<<"\n  It is your turn again!"; break;
		default:
			cout<<"\n Nothing"<<endl;
	}
}

void createMap(Place** map){
	map[0]= new Special("Start", Start, 0);
	map[1]= new City("Chicago", 10000, 1);
	map[2]= new City("Berlin", 9000, 2);
	map[3]= new Special("Move forward 3 places",Forward_3_places, 3);
	map[4]= new City("Moskow", 11000, 4);
	map[5]= new City("Las Vegas", 12000, 5);
	map[6]= new City("London", 10000, 6);
	map[7]= new Special("Jail", Jail, 7);
	map[8]= new Special("Move back 3 places", Back_3_places, 8);
	map[9]= new City("Monaco", 30000, 9);
	map[10]=new City("Ohrid", 7000, 10);
	map[11]=new City("Tokyo", 13000, 11);
	map[12]=new City("New York", 19000, 12);
	map[13]=new City("Texas", 11000, 13);
	map[14]=new Special("Move forward 5 places",Forward_5_places, 14);
	map[15]=new Special("Move back 5 places", Back_5_places, 15);
	map[16]=new City("Sidney", 15000, 16);
	map[17]=new City("Mexico City", 16000, 17);
	map[18]=new Special("You won another turn", Your_turn, 18);
	map[19]=new City("Amsterdam", 15000, 19);
}

vector<int> createPlayers(Player** players, int numPlayers){
	vector<int> locations(numPlayers);
	for(int i=0; i<numPlayers; i++){
		cout<<"  Player "<<i+1<<" name > ";
		string name;
		cin>>name;
		players[i] = new Player(name);
	}
	return locations;
}

void printLine(){
	cout<<"\t\t\t\t\t*********************"<<endl;
}

void printMapHandler(Place** map, vector<int> locations){
	size_t size = locations.size();
	int pos1 = locations[0];
	int pos2 = locations[1];
	if(size==2){
		printMap(map, pos1, pos2);
		return;
	}
	else if(size==3){
		int pos3 = locations[2];
		printMap(map, pos1, pos2, pos3);
		return;
	}
	else if(size==4){
		int pos3 = locations[2];
		int pos4 = locations[3];
		printMap(map, pos1, pos2, pos3, pos4);
		return;
	}
}

void printMap(Place** map, int pos1, int pos2){
	printLine();
	cout<<"\t\t\t\t\t\tTHE MAP"<<endl;
	printLine();
	for(int i=0; i<NUM_PLACES; i++){
		cout<<"\t\t\t\t\t"<<map[i]->getName();
		if(i==pos1)
			cout<<" *P1";
		if(i==pos2)
			cout<<" *P2";
		cout<<endl;
	}
}

void printMap(Place** map, int pos1, int pos2, int pos3){
	printLine();
	cout<<"\t\t\t\t\t\tTHE MAP"<<endl;
	printLine();
	for(int i=0; i<NUM_PLACES; i++){
		cout<<"\t\t\t\t\t"<<map[i]->getName();
		if(i==pos1)
			cout<<" *P1";
		if(i==pos2)
			cout<<" *P2";
		if(i==pos3)
			cout<<" *P3";
		cout<<endl;
	}
}

void printMap(Place** map, int pos1, int pos2, int pos3, int pos4){
	printLine();
	cout<<"\t\t\t\t\t\tTHE MAP"<<endl;
	printLine();
	for(int i=0; i<NUM_PLACES; i++){
		cout<<"\t\t\t\t\t"<<map[i]->getName();
		if(i==pos1)
			cout<<" *P1";
		if(i==pos2)
			cout<<" *P2";
		if(i==pos3)
			cout<<" *P3";
		if(i==pos4)
			cout<<" *P4";
		cout<<endl;
	}
}



int roll(){
	int r = rand()%8+1;
	cout<<"  You rolled "<<r;
	return r;
}

void choseNumPlayers(int& numPlayers){
	do{
		cout<<"  Chose number of players [2-4] >";
		cin>>numPlayers;
	}while(numPlayers<2 || numPlayers>4);
}

void welcomeMessage(){
	cout<<"\t\t\t\t********************************************"<<endl;
	cout<<"\t\t\t\t\t\tMONOPOLY 2020	"<<endl;
	cout<<"\t\t\t\t********************************************"<<endl;
	
}

bool playerOut(int indx, int& numPlayers, Player* players[], Place* map[]){
	if(--numPlayers<=1){
		return gameOverF(players[(indx+1)%(numPlayers+1)]);
	}
	system("CLS");
	printLine();
	cout<<"\t\t\t\t\t    PLAYER OUT !!!"<<endl;
	printLine();
	players[indx]->getInfo();
	cout<<endl<<"  ";
	
	vector<int> ownedPlaces = players[indx]->getPlaces();
	
	for(int& x : ownedPlaces){
		map[x]->removeOwner();
	}
	
	delete players[indx];
	
	return false;
}

bool gameOverF(Player* winner){
	system("CLS");
	printLine();
	cout<<"\t\t\t\t\t    GAME OVER !!!"<<endl;
	printLine();
	cout<<"\n\t\t\t\t\t\tWinner is: ";
	cout<<"\n\t\t\t\t\t";
	winner->getInfo();
	cout<<endl<<endl<<endl<<endl<<endl;
	return true;
}

void destroyPlayers(Player* players[], int numPlayers){
	for(int i=0; i<numPlayers; i++)
		delete players[i];
}

void destroyMap(Place* map[]){
	for(int i=0; i<NUM_PLACES; i++)
		delete map[i];
}
