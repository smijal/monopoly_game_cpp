#include<set>
#include<iostream>
#include<vector>
using namespace std;

#ifndef PLAYER_H
#define PLAYER_H

class Player{
	private:
		int money;
		set<string> owned_places;
		vector<int> owned_places_indexes;
		std::string name;
		int location; //0 to 32
	public:
		//constructors/destructors
		Player();
		Player(string name);
		~Player();
	
		//setters
		void addMoney(int m);
		bool subMoney(int m);
		bool purchase(int m);
		void addPlace(string name, int indx);
		void setLocation(int loc);
		
		
		//getters
		void getInfo();
		void print_places();
		int getMoney();
		int getLocation();
		vector<int> getPlaces();
		string getName();

};
	

#endif
