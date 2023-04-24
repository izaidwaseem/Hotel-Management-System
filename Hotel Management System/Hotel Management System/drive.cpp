#include<iostream>
#include<fstream>
#include<string>
#include"Hotel.h"
#include"Customer.h"
#include"Rooms.h"
#include"Standard.h"
#include"Standard.h"
#include"Moderate.h"
#include"Superior.h"
#include"JrSuite.h"
#include"Suite.h"
using namespace std;
int Standard::counter = 0;
int Moderate::counter = 0;
int Superior::counter = 0;
int JrSuite::counter = 0;
int Suite::counter = 0;
int main()
{
	//ifstream fin;
	//ofstream fout;
	//fin.open("Customers.txt");
	/*if (!fin.is_open())
	{
		cout << "Unable to access Customer Data" << endl;
		return 0;
	}
	//fin.open("Rooms.txt");
	if (!fin.is_open())
	{
		cout << "Unable to access Rooms' Data" << endl;
		return 0;
	}*/
	/*Standard obj;
	Moderate obj1;
	Superior obj2;
	JrSuite obj3;
	Suite obj4;
	ofstream fout;
	Standard ob;
	obj.add();
	obj.reserve();
	obj1.add();
	obj2.add();
	obj3.add();
	obj4.add();
	fout.open("Rooms.txt");
	obj.output(fout);
	obj1.output(fout);
	obj2.output(fout);
	obj3.output(fout);
	obj4.output(fout);
	obj.display();
	obj1.display();
	obj2.display();
	obj3.display();
	obj4.display();
	obj.RoomsOccupied();*/
	ifstream fin,gin,hin,iin,jin,kin;
	Standard temp;
	Moderate temp2;
	Superior temp3;
	JrSuite temp4;
	Suite temp5;
	Customer* test = new Customer[15];
	fin.open("Customers.txt");
	gin.open("Rooms.txt");
	/*hin.open("Rooms.txt");
	iin.open("Rooms.txt");
	jin.open("Rooms.txt");
	kin.open("Rooms.txt");*/
	if (fin.is_open()&&gin.is_open())
	{
		for (int i = 0;i < 10;i++)
		{
			test[i].dataLoad(fin);
		}
		temp.add(fin, test[10]);
		/*temp2.add(hin, test[11]);
		temp3.add(iin, test[12]);
		temp4.add(jin, test[13]);
		temp5.add(kin, test[14]);*/
		//test[10].checkin(fin);
	}
	//fin.close();
	//test[0].checkin(fin);
	/*Customer ob;
	ob.checkin(fin);*/
	ofstream fout,gout;
	fout.open("Customers.txt");
	for (int i = 0;i < 11;i++)
	{
		test[i].output(fout);
	}
	gout.open("Rooms.txt");
	temp.output(gout);
	temp2.output(gout);
	temp3.output(gout);
	temp4.output(gout);
	temp5.output(gout);
}
