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
#include<time.h>
#include<ctime>
#include<Windows.h>
#include<stdio.h>
using namespace std;
int Customer::counter = 0;
Customer* increaseSize(Customer* ptr, int& size)
{
	int temp = size;
	size = size * 2;
	Customer* arr;
	arr = new Customer[size];
	for (int i = 0;i < temp;i++)
	{
		arr[i] = ptr[i];
	}
	delete[] ptr;
	ptr = NULL;
	return arr;
}
int checkINCnt(Customer* obj, int total, string temp)
{
	int cnt = 0;
	string date;
	date = temp;
	for (int i = 0; i < total; i++)
	{
		if (date == obj[i].Getcheckin_date())
			cnt++;
	}
	return cnt;
}
int checkOUTCnt(Customer* obj, int total, string temp)
{
	int cnt = 0;
	string date;
	date = temp;
	for (int i = 0; i < total; i++)
	{
		if (date == obj[i].Getcheckout_date())
			cnt++;
	}
	return cnt;
}
int main()
{
	ifstream fin, gin, hin, iin, jin, kin;
	int size = 15;
	string date;
	Customer* Cus = new Customer[size];
	fin.open("Customers.txt");
	gin.open("Rooms.txt");
	Standard std;
	Moderate mod;
	Superior sup;
	JrSuite jnr;
	Suite st;
	int temp_total = 0;
	if (fin.is_open() && gin.is_open())
	{
		fin >> temp_total;
		if (temp_total >= size)
			Cus = increaseSize(Cus, size);
		for (int i = 0;i < temp_total;i++)
		{
			Cus[i].dataLoad(fin);
		}
	}
	int menu = -1;
	int type = 0;
	int std_cnt = 0, mod_cnt = 0, sup_cnt = 0, jnr_cnt = 0, st_cnt = 0;
	system("cls");
	cout << "****************************************************************************************************************" << endl;
	cout << "\t\t\t\t\HOT-EL INTERNATIONAL INC" << endl;
	cout << "****************************************************************************************************************" << endl;
	int i = 0;
	char a = 0;
	cout << endl << endl;
	while (menu != 0)
	{
		cout << "***************************************************" << endl;
		cout << "*\t=> Press 1 to reserve a room              *" << endl;
		cout << "*\t=> Press 2 to Check-In a Customer/Visitor *" << endl;
		cout << "*\t=> Press 3 to view reserved rooms         *" << endl;
		cout << "*\t=> Press 4 to see Detail Report           *" << endl;
		cout << "*\t=> Press 0 to EXIT                        *" << endl;
		cout << "***************************************************" << endl;
		cin >> menu;
		switch (menu)
		{
		case 1:
		{
			cout << "****************************************" << endl;
			cout << "*\t=> Press 1 for Standard        *" << endl;
			cout << "*\t=> Press 2 for Moderate        *" << endl;
			cout << "*\t=> Press 3 for Superior        *" << endl;
			cout << "*\t=> Press 4 for Jr.Suite        *" << endl;
			cout << "*\t=> Press 5 for Suite           *" << endl;
			cout << "****************************************" << endl;
			type = 0;
			cout << "Enter :";
			cin >> type;
			switch (type)
			{
			case 1:
			{
				if (temp_total >= size)
					Cus = increaseSize(Cus, size);
				std.reserve(fin, Cus[temp_total],Cus);
				temp_total++;
				std_cnt++;
				cout << "Have you paid in advance ? : (Y,N)" << endl;
				cin >> a;
				if (a == 'Y')
					Cus[temp_total - 1].setBalance(0);
				else
					cout << "Balance : " << Cus[temp_total - 1].getBal() << endl;
				cout << Cus[temp_total - 1] << endl;
				Sleep(2000);
				system("cls");
				break;
			}
			case 2:
			{
				if (temp_total >= size)
					Cus = increaseSize(Cus, size);
				mod.reserve(fin, Cus[temp_total],Cus);
				temp_total++;
				mod_cnt++;
				cout << "Have you paid in advance ? : (Y,N)" << endl;
				cin >> a;
				if (a == 'Y')
					Cus[temp_total - 1].setBalance(0);
				else
					cout << "Balance : " << Cus[temp_total - 1].getBal() << endl;
				cout << Cus[temp_total - 1] << endl;
				Sleep(2000);
				system("cls");
				break;
			}
			case 3:
			{
				if (temp_total >= size)
					Cus = increaseSize(Cus, size);
				sup.reserve(fin, Cus[temp_total], Cus);
				temp_total++;
				sup_cnt++;
				cout << "Have you paid in advance ? : (Y,N)" << endl;
				cin >> a;
				if (a == 'Y')
					Cus[temp_total - 1].setBalance(0);
				else
					cout << "Balance : " << Cus[temp_total - 1].getBal() << endl;
				cout << Cus[temp_total - 1] << endl;
				Sleep(2000);
				system("cls");
				break;
			}
			case 4:
			{
				if (temp_total >= size)
					Cus = increaseSize(Cus, size);
				jnr.reserve(fin, Cus[temp_total], Cus);
				temp_total++;
				jnr_cnt++;
				cout << "Have you paid in advance ? : (Y,N)" << endl;
				cin >> a;
				if (a == 'Y')
					Cus[temp_total - 1].setBalance(0);
				else
					cout << "Balance : " << Cus[temp_total - 1].getBal() << endl;
				cout << Cus[temp_total - 1] << endl;
				Sleep(2000);
				system("cls");
				break;
			}
			case 5:
			{
				if (temp_total >= size)
					Cus = increaseSize(Cus, size);
				st.reserve(fin, Cus[temp_total], Cus);
				temp_total++;
				st_cnt++;
				cout << "Have you paid in advance ? : (Y,N)" << endl;
				cin >> a;
				if (a == 'Y')
					Cus[temp_total - 1].setBalance(0);
				else
					cout << "Balance : " << Cus[temp_total - 1].getBal() << endl;
				cout << Cus[temp_total - 1] << endl;
				Sleep(2000);
				system("cls");
				break;
			}
			default:
			{
				cout << "Invalid Input !" << endl;
				break;
			}
			}
			break;
		}
		case 2:
		{
			cout << "****************************************" << endl;
			cout << "*\t=> Press 1 for Standard        *" << endl;
			cout << "*\t=> Press 2 for Moderate        *" << endl;
			cout << "*\t=> Press 3 for Superior        *" << endl;
			cout << "*\t=> Press 4 for Jr.Suite        *" << endl;
			cout << "*\t=> Press 5 for Suite           *" << endl;
			cout << "****************************************" << endl;
			type = 0;
			cout << "Enter :";
			cin >> type;
			switch (type)
			{
			case 1:
			{
				if (temp_total >= size)
					Cus = increaseSize(Cus, size);
				std.add(fin, Cus[temp_total],Cus);
				temp_total++;
				std_cnt++;
				cout << "Have you paid in advance ? : (Y,N)" << endl;
				cin >> a;
				if (a == 'Y')
					Cus[temp_total - 1].setBalance(0);
				else
					cout << "Balance : " << Cus[temp_total - 1].getBal() << endl;
				cout << Cus[temp_total - 1] << endl;
				Sleep(2000);
				system("cls");
				break;
			}
			case 2:
			{
				if (temp_total >= size)
					Cus = increaseSize(Cus, size);
				mod.add(fin, Cus[temp_total], Cus);
				temp_total++;
				mod_cnt++;
				cout << "Have you paid in advance ? : (Y,N)" << endl;
				cin >> a;
				if (a == 'Y')
					Cus[temp_total - 1].setBalance(0);
				else
					cout << "Balance : " << Cus[temp_total - 1].getBal() << endl;
						cout << Cus[temp_total - 1] << endl;
				Sleep(2000);
				system("cls");
				break;
			}
			case 3:
			{
				if (temp_total >= size)
					Cus = increaseSize(Cus, size);
				sup.add(fin, Cus[temp_total], Cus);
				temp_total++;
				sup_cnt++;
				cout << "Have you paid in advance ? : (Y,N)" << endl;
				cin >> a;
				if (a == 'Y')
					Cus[temp_total - 1].setBalance(0);
				else
					cout << "Balance : " << Cus[temp_total - 1].getBal() << endl;
						cout << Cus[temp_total - 1] << endl;
				Sleep(2000);
				system("cls");
				break;
			}
			case 4:
			{
				if (temp_total >= size)
					Cus = increaseSize(Cus, size);
				jnr.add(fin, Cus[temp_total], Cus);
				temp_total++;
				jnr_cnt++;
				cout << "Have you paid in advance ? : (Y,N)" << endl;
				cin >> a;
				if (a == 'Y')
					Cus[temp_total - 1].setBalance(0);
				else
					cout << "Balance : " << Cus[temp_total - 1].getBal() << endl;
						cout << Cus[temp_total - 1] << endl;
				Sleep(2000);
				system("cls");
				break;
			}
			case 5:
			{
				if (temp_total >= size)
					Cus = increaseSize(Cus, size);
				st.add(fin, Cus[temp_total], Cus);
				temp_total++;
				st_cnt++;
				cout << "Have you paid in advance ? : (Y,N)" << endl;
				cin >> a;
				if (a == 'Y')
					Cus[temp_total - 1].setBalance(0);
				else
					cout << "Balance : " << Cus[temp_total - 1].getBal() << endl;
						cout << Cus[temp_total - 1] << endl;
				Sleep(2000);
				system("cls");
				break;
			}
			default:
			{
				cout << "Invalid Input !" << endl;
				break;
			}
			}
			break;
		case 3:
		{
			cout << "****************************************" << endl;
			cout << "*\t=> Press 1 for Standard        *" << endl;
			cout << "*\t=> Press 2 for Moderate        *" << endl;
			cout << "*\t=> Press 3 for Superior        *" << endl;
			cout << "*\t=> Press 4 for Jr.Suite        *" << endl;
			cout << "*\t=> Press 5 for Suite           *" << endl;
			cout << "****************************************" << endl;
			type = 0;
			cout << "Enter :";
			cin >> type;
			switch (type)
			{
			case 1:
			{
				std.RoomsOccupied();
				break;
			}
			case 2:
			{
				mod.RoomsOccupied();
				break;
			}
			case 3:
			{
				sup.RoomsOccupied();
				break;
			}
			case 4:
			{
				jnr.RoomsOccupied();
				break;
			}
			case 5:
			{
				st.RoomsOccupied();
				break;
			}
			default:
			{
				cout << "Invalid Input !" << endl;
				break;
			}
			}
			break;
		case 4:
		{
			cout << "Kindly enter the date for Detail report (DD-MM-YY) : ";
			string date;
			cin >> date;
			cout << "Checked-In : ";
			cout << checkINCnt(Cus, temp_total, date) << endl << endl;
			cout << "Checked-Out : ";
			cout << checkOUTCnt(Cus, temp_total, date) << endl << endl;
			cout << "Number of Standard rooms Reseved are : " << std_cnt << endl;
			cout << "Number of Moderate rooms Reseved are : " << mod_cnt << endl;
			cout << "Number of Superior rooms Reseved are : " << sup_cnt << endl;
			cout << "Number of Junior Suite rooms Reseved are : " << jnr_cnt << endl;
			cout << "Number of Suite rooms Reseved are : " << st_cnt << endl << endl << endl;

			cout << "Standard : " << endl;
			std.display();
			cout << endl;
			cout << "Moderate :" << endl;
			mod.display();
			cout << endl;
			cout << "Superior : " << endl;
			sup.display();
			cout << endl;
			cout << "Junior suite : " << endl;
			jnr.display();
			cout << endl;
			cout << "Suite : " << endl;
			st.display();
			cout << endl;
			break;
		}
		case 0:
		{
			ofstream fout, gout;
			fout.open("Customers.txt");
			fout << temp_total << endl;
			for (int i = 0;i < temp_total;i++)
			{
				Cus[i].output(fout);
			}
			gout.open("Rooms.txt");
			std.output(gout);
			mod.output(gout);
			sup.output(gout);
			jnr.output(gout);
			st.output(gout);
			cout << "Thanks !" << endl;
			delete[] Cus;
			Cus = NULL;
			return 0;
			break;

		}
		default:
		{
			cout << "Invalid Number entered !" << endl;
		}
		}
		i++;
		}

		}
	}
}

