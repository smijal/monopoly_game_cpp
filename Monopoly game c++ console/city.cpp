#include<iostream>
#include "city.h"

using namespace std;

	City::City(string name, int price, int index) : Place(name, price, "City", index){
		this->owned = false;
	}
	
	void City::setOwner(string name){
		this->ownedBy = name;
		this->owned=true;
	}
	
	void City::removeOwner(){
		this->ownedBy="None";
		this->owned=false;
	}
	
	bool City::isOwned(){
		return this->owned;
	}
	
	string City::getOwner(){
		return this->ownedBy;
	}
