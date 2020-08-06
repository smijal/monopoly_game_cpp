#include "player.h"
#include<iostream>

using namespace std;
		
		//constuctors
		Player::Player(){
		}
		
		Player::Player(string name){
			this->name = name;
			this->money = 200000;
			this->location=0;
		}
		
		Player::~Player(){
			cout<<"Player destructor called"<<endl;
		}
		
		//setters
		void Player::addMoney(int m){
			this->money+=m;
		}
		bool Player::subMoney(int m){
			this->money-=m;
			if(this->money<=0){
				this->money=0;
				return true;
			}
				
			else
				return false;	
		}
		
		bool Player::purchase(int m){
			try{
				if(this->money-m<0)
					throw 999;	
			}
			catch (int x){
				cout<<endl;
				cout<<"\n  Not enough money for purchase... Error "<<x<<endl;
				return false;
			}

			this->money-=m;
			cout<<"  Done.";
			cout<<"\n  New budget: $"<<this->money;
			return true;
		}
		
		void Player::addPlace(string name, int indx){
			this->owned_places.insert(name);
			this->owned_places_indexes.push_back(indx);
		}
		
		void Player::setLocation(int loc){
			this->location=loc;
		}
		
		//getters
		void Player::getInfo(){
			cout<<endl;
			cout<<"\n  Player name: "<<this->name<<"	 Money: $"<<this->money<<" 	";
			print_places();
			
		}
		void Player::print_places(){
			set<string>::iterator it=this->owned_places.begin();
			if(it==this->owned_places.end()){
				cout<<"\n  Places owned: None";
				return;
			}
			cout<<"\n  Places owned: ";
			for(it; it!=this->owned_places.end(); it++)
				cout<<*it<<", ";
		}
		
		int Player::getLocation(){
			return this->location;
		}
		string Player::getName(){
			return this->name;
		}
		
		int Player::getMoney(){
			return this->money;
		}
		
		vector<int> Player::getPlaces(){
			return this->owned_places_indexes;
		}
		

