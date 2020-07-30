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
