
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include "player.h"
#include "city.h"
#include "special.h"
#include <time.h>
#include "util.h"
#include<windows.h>

using namespace std;

//enum Task {Forward_3_places, Forward_5_places, Back_3_places, Back_5_places, Your_turn, Jail, Start};

int main(){
	
	HWND console = GetConsoleWindow();
  	RECT ConsoleRect;
 	GetWindowRect(console, &ConsoleRect); 
  	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 800, 600, TRUE);
	srand(time(NULL));
	bool gameOver=false;
	
	welcomeMessage();
	
	int numPlayers;
	int i=0;
	
	choseNumPlayers(numPlayers);
	Player* players[numPlayers];
	vector<int> locations = createPlayers(players, numPlayers);
	
	system("CLS");
	
	Place* map[NUM_PLACES];
	createMap(map);
	printMapHandler(map,locations);
	
	cout<<"\n  START";
	
	while(!gameOver){
		cout<<endl;
		cout<<"  "<<players[i]->getName()<<"'s turn...";
		cout<<"\n  Budget: $"<<players[i]->getMoney();
		players[i]->print_places();
		char key;
		do{
			cout<<"\n  Press 'R' to roll... ";
			cin>>key;	
		}while(key!='R' && key!='r');

		
		int r = roll();
		r+=players[i]->getLocation();
		r%=NUM_PLACES;
		
		cout<<"\n  Moving to "<<map[r]->getName();
		map[r]->getInfo();
		
		if(map[r]->getType()=="City"){
			do{
				cout<<"\n  Would you like to buy it? [Y/N] >";
				cin>>key;
				if(key=='Y' || key=='y'){
					players[i]->purchase(map[r]->getCost());
					players[i]->addPlace(map[r]->getName());
					break;
				}
					
				else if(key=='N' || key=='n'){
					cout<<"\n  NO";
					break;
				}
		
			}while(true);	
		}
		
		else{
			specialExecution(map[r]->getTask(), r);
		}
		
		players[i]->setLocation(r);
		
		vector<int> locations;
		
		
		
		cout<<endl;
		system("PAUSE");
		system("CLS");
		cout<< '\a';
		
		for(int i=0; i<numPlayers; i++){
			locations.push_back(players[i]->getLocation());
		}
		
		printMapHandler(map,locations);
		
		i=(i+1)%numPlayers;
	}
	
	
	
	
	return 0;
}
