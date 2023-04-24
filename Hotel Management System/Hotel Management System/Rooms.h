#include<iostream>
using namespace std;
#pragma once
class Rooms
{
protected:
	//data members
	int price;
	//float time;
public:
	//void getTime();
	//member functions + pure virtual function:
	virtual void display() = 0;
};

