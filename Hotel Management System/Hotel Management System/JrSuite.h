#include<iostream>
#include<fstream>
#include"Rooms.h"
#include"Customer.h"
using namespace std;
#pragma once
//multiple inheritance
class JrSuite :public Rooms,public Customer
{
private:
	//data members
	int noOfRooms;
	int juniorsuite[10][5];
public:
	//constructors
	JrSuite();
	//member functions
	void RoomsOccupied();
	void add(ifstream& ob, Customer& obj, Customer* arr);
	void reserve(ifstream& ob, Customer& obj, Customer* arr);
	void output(ofstream& ob);
	void display();
};

