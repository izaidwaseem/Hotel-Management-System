#include<iostream>
#include"Rooms.h"
#include"Customer.h"
using namespace std;
#pragma once
class Moderate:public Rooms,public Customer
{
private:
	int noOfRooms;
	//static int counter;
	int moderate[10][5] ;
	
public:
	Moderate();
	//Moderate(overloading)
	void add(ifstream& ob, Customer& obj,Customer *arr);
	void reserve(ifstream& ob, Customer& obj, Customer* arr);
	void output(ofstream &ob);
	void RoomsOccupied();
	void display();
};

