#include<iostream>
#include "place.h"
#include "city.h"
#include "special.h"
#include "player.h"
#include "util.h"

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
	map[0]= new Special("Start", Start);
	map[1]= new City("Chicago", 10000);
	map[2]= new City("Berlin", 9000);
	map[3]= new Special("Move forward 3 places",Forward_3_places);
	map[4]= new City("Moskow", 11000);
	map[5]= new City("Las Vegas", 12000);
	map[6]= new City("London", 10000);
	map[7]= new Special("Jail", Jail);
	map[8]= new Special("Move back 3 places", Back_3_places);
	map[9]= new City("Monaco", 30000);
	map[10]=new City("Ohrid", 7000);
	map[11]=new City("Tokyo", 13000);
	map[12]=new City("New York", 19000);
	map[13]=new City("Texas", 11000);
	map[14]=new Special("Move forward 5 places",Forward_5_places);
	map[15]=new Special("Move back 5 places", Back_5_places);
	map[16]=new City("Sidney", 15000);
	map[17]=new City("Mexico City", 16000);
	map[18]=new Special("You won another turn", Your_turn);
	map[19]=new City("Amsterdam", 15000);
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
	cout<<"\n\t\t\t\t  THE MAP"<<endl;
	printLine();
	for(int i=0; i<NUM_PLACES; i++){
		cout<<map[i]->getName();
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
	cout<<"\tTHE MAP"<<endl;
	printLine();
	for(int i=0; i<NUM_PLACES; i++){
		cout<<map[i]->getName();
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

void print_map(){
	
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

