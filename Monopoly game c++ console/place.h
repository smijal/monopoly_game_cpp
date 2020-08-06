#include<iostream>

using namespace std;

#ifndef PLACE_H
#define PLACE_H

enum Task {Forward_3_places, Forward_5_places, Back_3_places, Back_5_places, Your_turn, Jail, Start};

class Place{
	protected:
		string name;
		string type;
		int price;
		int index;
		
		Place(string name, int price, string type, int index);

	public:
		//constructors/destuctors
		Place();
		~Place();
		
		//setters
		void changePrice(int newPrice);
		virtual void setOwner(string name);
		virtual void removeOwner();		
		void doublePrice();
		void normalPrice();
		
		//getters		
		void getInfo();
		int getCost();
		string getType();
		string getName();
		virtual Task getTask();
		virtual bool isOwned();
		virtual string getOwner();
		int getIndex_byName(string name);
};


#endif
