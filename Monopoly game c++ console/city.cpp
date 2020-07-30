#include<iostream>
#include "city.h"

using namespace std;

	City::City(string name, int price) : Place(name, price, "City"){
		this->owned = false;
	}
	
	void City::setOwner(string name){
		this->ownedBy = name;
		owned=true;
	}