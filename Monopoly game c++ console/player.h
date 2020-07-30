#include<set>
#include<iostream>
using namespace std;

#ifndef PLAYER_H
#define PLAYER_H

class Player{
	private:
		int money;
		set<string> owned_places;
		std::string name;
		int location; //0 to 32
	public:
		//constructors/destructors
		Player();
		Player(string name);
		~Player();
	
		//setters
		void addMoney(int m);
		void subMoney(int m);
		bool purchase(int m);
		void addPlace(string name);
		void setLocation(int loc);
		
		
		//getters
		void getInfo();
		void print_places();
		int getMoney();
		int getLocation();
		string getName();

};
	

#endif
