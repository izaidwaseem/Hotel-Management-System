#include "Customer.h"
#include<fstream>
#include<iostream>
#include<ctime>
#include<time.h>
Customer::Customer()
{
	counter++;
	age = 0;
	gender = 0;
	name = "Default";
	id = "Default";
	room = 0;
	floor = 0;
	days = 0;
	checkin_time = "Default";
	checkin_date = "Default";
	checkout_time = "Default";
	checkout_date = "Default";
	type = "Default";
	total = 0;
	Size = 10;
}
//overloaded
Customer::Customer(string Name, int AGE, char gen, string ID )
{
	this->name = Name;
	this->gender = gen;
	this->id = ID;
	this ->age=AGE;
}
bool Customer:: searchCustomer(ifstream &ob,Customer *arr) //searching a particular id
{
	string ID;
	cout << "Enter Your Id Number(12345-1234) : ";
	cin >> ID;
	for (int i = 0;i < counter;i++)
	{
		if (ID == arr[i].id)
		{
			index = i;
			return true;
		}
	}
	return false;
}
void Customer::dataLoad(ifstream& ob)   //reading data from file 
{
	ob >> id;
	ob >> name;
	ob >> gender;
	ob >> age;
	ob >> floor;
	ob >> days;
	ob >> type;
	ob >> room;
	ob >> checkin_time;
	ob >> checkin_date;
	ob >> checkout_time;
	ob >> checkout_date;
	ob >> balance;
}
void Customer::setFloor(int num)
{
	floor = num;
}
void Customer::setroom(int num)
{
	room = num;
}
void Customer::checkin(ifstream &ob,Customer *arr)       //function for checkin of a customer
{
	cout << "\tCustomer found ! " << endl << endl;
	id = arr[index].id;
	cout << id<<" ";
	name = arr[index].name;
	cout << name << " ";
	gender = arr[index].gender;
	cout << gender << " ";
	age = arr[index].age;
	cout << age << endl;
	cout << "Enter remaining info. : " << endl << endl;
	cout << "Enter No. of days to stay : ";
	cin >> days;
	cout << "Enter Checkin Time(hr:min) : ";
	cin >> checkin_time;
	cout << "Enter Checkin Date(DD-MM-YY) : ";
	cin >> checkin_date;
	cout << "Enter Checkout Time(hr:min) : ";
	cin >> checkout_time;
	cout << "Enter Checkout Date(DD-MM-YY) : ";
	cin >> checkout_date;
}
void Customer::newcustomer()                        //checking_in of a new customer 
{
	cout << "Kindly enter ur information " << endl;
	cout << "Enter your ID number(12345-1234) : ";
	cin >> id;
	cout << "Enter your name(without any space) : ";
	cin >> name;
	cout << "Enter your gender (M,F) :";
	cin >> gender;
	cout << "Enter your age : ";
	cin >> age;
	cout<<"Enter the number of days of stay : ";
	cin >> days;
	cout << "Enter check-in time(hr:min) : ";
	cin >> checkin_time;
	cout << "Enter check-in date(DD-MM-YY) : ";
	cin >> checkin_date;
	cout<<"Enter check-out time(hr:min) : ";
	cin>> checkout_time;
	cout<<"Enter check-out date(DD-MM-YY) : ";
	cin>> checkout_date;
	cout  <<  endl;
}
void Customer::output(ofstream &ob)                  // FILING OUT of customer data 
{
	ob << id << " ";
	ob << name << " ";
	ob << gender << " ";
	ob << age << " ";
	ob << floor << " ";
	ob << days << " ";
	ob << type << " ";
	ob << room << " ";
	ob << checkin_time << " ";
	ob << checkin_date << " ";
	ob << checkout_time << " ";
	ob << checkout_date << " ";
	ob << balance;
	ob << endl;
	cout << endl;
}
int  Customer::getTotal()
{
	return total;
}
void Customer::setTotal(int num)
{
	total = num;
}
void Customer:: CalRemainingTime(ifstream &ob)
{
	//if(searchCustomer(ob))
	//{
	//	this->checkout_time;
	//	time_t currenttime;
	//	cout << ctime(&currenttime);
	//	difftime(currenttime, currenttime);
	//}
	//else
	//	cout<<"customer doesnt exist"<<endl;
}
int Customer::getDays()
{
	return days;
}
void Customer::setBalance(int a)
{
	balance = a;
}
float Customer::getBal()
{
	return balance;
}
void Customer::setType(const string Type)
{
	type = Type;
}

string Customer::Getcheckin_date()
{
	return checkin_date;
}
string Customer::Getcheckout_date()
{
	return checkout_date;
}
ostream& operator<<(ostream& output, Customer obj)               //  Insertion operator Overload 
{
	output << "Entered Data : ";
	cout << endl << endl;
	output << obj.id << " " << obj.name << " " << obj.gender << " " << obj.age;
	output <<" "<< obj.floor << " " << obj.days << " " << obj.type << " " << obj.room;
	output << " " << obj.checkin_time << " " << obj.checkin_date << " " << obj.checkout_time;
	output << " " << obj.checkout_date << endl;
	return output;
}
