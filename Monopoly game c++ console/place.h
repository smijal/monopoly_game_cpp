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
		
		Place(string name, int price, string type);

	public:
		Place();
		~Place();

		void getInfo();
		int getCost();
		void changePrice(int newPrice);
		string getType();
		string getName();
		virtual Task getTask();
};


#endif
