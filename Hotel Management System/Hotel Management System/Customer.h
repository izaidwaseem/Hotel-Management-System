#include<iostream>
#include<time.h>
using namespace std;
#pragma once
class Customer
{
private:
	//data members/ atributes of the customer
	int total;
	int Size;
	static int counter;
	int index;
	int age;
	char gender;
	string name;
	string id;
	int room;
	int floor, days;
	int balance;
	string checkin_time, checkin_date, checkout_time, checkout_date, type;
public:
	//Constructor and overloaded constructor
	Customer();
	Customer(string Name, int AGE, char gen, string ID);
	//members functions
	void checkin(ifstream &ob,Customer * arr);
	void newcustomer();
	//void increaseSize();
	bool searchCustomer(ifstream &ob,Customer *arr);
	void dataLoad(ifstream &ob);
	void output(ofstream&ob);
	void CalRemainingTime(ifstream &ob);
	string Getcheckin_date();
	string Getcheckout_date();
	//<< overloading
	friend ostream& operator<<(ostream& output, Customer obj);
	//getters and setters
	void setFloor(int num);
	void setroom(int num);
	int  getTotal();
	void setTotal(int num);
	void setBalance(int a);
	float getBal();
	int getDays();
	void setType(const string Type);
};
