#include<iostream>
#include"Rooms.h"
#include"Customer.h"
#include<fstream>
using namespace std;
#pragma once
class Superior:public Rooms,public Customer
{
private:
	//data members
	int noOfRooms;
	int superior[10][5];
public:
	//constructor
	Superior();
	//member functions
	void add(ifstream& ob, Customer& obj, Customer* arr);
	void reserve(ifstream& ob, Customer& obj, Customer* arr);
	void output(ofstream& ob);
	void RoomsOccupied();
	void display();
};

