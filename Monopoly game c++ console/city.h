#include<iostream>
#include "place.h"
using namespace std;

#ifndef CITY_H
#define CITY_H

class City : public Place{
	private:
		string ownedBy;
		bool owned;
	public:
		City(string name, int price);
		void setOwner(string name);
};

#endif
