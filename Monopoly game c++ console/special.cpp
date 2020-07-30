#include<iostream>
#include "special.h"		

using namespace std;

	Special::Special(string name, Task task) : Place(name, 0, "Special"){
		this->task=task;
	}
	
	Task Special::getTask(){
		return this->task;
	}
