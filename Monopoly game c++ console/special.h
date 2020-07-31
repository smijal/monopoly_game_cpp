#include<iostream>
#include "place.h"
using namespace std;

#ifndef SPECIAL_H
#define SPECIAL_H

class Special : public Place{
	private:
		Task task;
		
	public:
		Special(string name, Task task, int index);
		Task getTask() override;
};

#endif
