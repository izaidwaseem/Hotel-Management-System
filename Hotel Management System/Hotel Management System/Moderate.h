#include<iostream>
#include"Rooms.h"
#include"Customer.h"
using namespace std;
#pragma once
class Moderate:public Rooms,public Customer
{
private:
	//data members
	int noOfRooms;
	int moderate[10][5] ;
public:
	//constructors
	Moderate();
	//member functions
	void add(ifstream& ob, Customer& obj,Customer *arr);
	void reserve(ifstream& ob, Customer& obj,Customer *arr);
	void output(ofstream &ob);
	void RoomsOccupied();
	void display();
};

