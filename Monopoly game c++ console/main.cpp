
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
#include <map>

using namespace std;

//enum Task {Forward_3_places, Forward_5_places, Back_3_places, Back_5_places, Your_turn, Jail, Start};

int main(){
	
	bool playing=true;
	
	while(playing){
		HWND console = GetConsoleWindow();
	  	RECT ConsoleRect;
	 	GetWindowRect(console, &ConsoleRect); 
	  	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 800, 600, TRUE);
		
		srand(time(NULL));
		
		bool gameOver=false;
		bool pOut=false;
		bool wait=false;
		
		welcomeMessage();
		
		int numPlayers;
		map<string,int> name_index;
		int i=0;
		
		choseNumPlayers(numPlayers);
		Player* players[numPlayers];
		vector<int> locations = createPlayers(players, numPlayers, name_index);
		
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
				if(!map[r]->isOwned()){
						do{
						cout<<"\n  Would you like to buy it? [Y/N] >";
						cin>>key;
						if(key=='Y' || key=='y'){
							if(!players[i]->purchase(map[r]->getCost()))
								break;
							players[i]->addPlace(map[r]->getName(), r);
							map[r]->setOwner(players[i]->getName());
							map[r]->doublePrice();
							break;
						}
							
						else if(key=='N' || key=='n'){
							cout<<"\n  NO";
							break;
						}
				
					}while(true);
				}
				else if (map[r]->isOwned() && map[r]->getOwner()!=players[i]->getName()){
					cout<<"\n  Private property!";
					cout<<"\n  You need to pay!"<<endl<<"  ";
					pOut=players[i]->subMoney(map[r]->getCost());
					players[name_index[map[r]->getOwner()]]->addMoney(map[r]->getCost());
				}
		
			}
			
			else{
				wait=specialExecution(map[r]->getTask(), r, players[i], pOut);
			}
			
			if(pOut)
				gameOver=playerOut(i, numPlayers, players, map);
			if(gameOver)
				break;
			
			players[i]->setLocation(r);
			
			vector<int> locations;
			
			cout<<endl<<"  ";
			system("PAUSE");
			system("CLS");
			cout<< '\a';
			
			
			for(int i=0; i<numPlayers; i++){
				locations.push_back(players[i]->getLocation());
			}
			
			printMapHandler(map,locations);
			pOut=false;
			
			if(!wait)
				i=(i+1)%numPlayers;
			else
				wait=false;
		}
		
		char inp='x';
		cout<<"\n\n  Press 'P' to play again or any other key to exit...";
		cin>>inp;	
		
		if(inp!='P' && inp!='p')
			playing=false;
		
		destroyPlayers(players, numPlayers);
		destroyMap(map);
		system("CLS");
		
	}
	

	return 0;
}
