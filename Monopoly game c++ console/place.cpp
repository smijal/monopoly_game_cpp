		#include<iostream>
		#include "place.h"
		
		using namespace std;
		
		Place::Place(string name, int price, string type){
			this->name=name;
			this->price=price;
			this->type = type;
		}

		Place::Place(){
		}
		
		Place::~Place(){
			//cout<<"Place Destructor called"<<endl;
		}
		void Place::getInfo(){
			cout<<endl;
			cout<<"  Place name: "<<this->name<<" 	Price: "<<this->price<<" 	Type: "<<this->type;
		}
		void Place::changePrice(int newPrice){
			this->price=newPrice;
		}
		string Place::getType(){
			return this->type;
		}
		string Place::getName(){
			return this->name;
		}
		Task Place::getTask(){
			return Start;
		}
		int Place::getCost(){
			return this->price;
		}
		bool Place::isOwned(){
			return false;
		}
		void Place::setOwner(string name){
			cout<<"\n  Owner cannot be set";
		}
		string Place::getOwner(){
			cout<<"\n  Owner can't get owner be";
		}
		void Place::doublePrice(){
			this->price*=2;
		}
