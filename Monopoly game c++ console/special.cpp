#include<iostream>
#include "special.h"		

using namespace std;

	Special::Special(string name, Task task, int index) : Place(name, 0, "Special", index){
		this->task=task;
	}
	
	Task Special::getTask(){
		return this->task;
	}
