/*#include "Standard.h"
#include<fstream>
Standard::Standard()
{
	noOfRooms = 50;
	counter++;
	for (int i = 0;i < 10;i++)
	{
		for (int j = 0;j < 5;j++)
			standard[i][j] = 0;
	}
}
void Standard::add()
{
	for (int i = 0;standard[room_no - 1][floor_no - 1] != 0;i++)
	{
		floor_no = 0;
		//cin >> floor_no;
		room_no = 0;
		//cin >> room_no;
	}
	if (standard[room_no - 1][floor_no - 1] = 0)
	{
		standard[room_no - 1][floor_no - 1] = 1;
		reserved++;
	}
	ifstream fin;
	
	string temp="Standard";
	fin.open("Rooms.txt");
	if (fin.is_open())
	{
		cout<<"*****"<<endl;
	    ofstream fout;
		fout.open("Text.txt");
		fout<<seekp(9);
		for (int i = 0;i < 10;i++)
		{
			for (int j = 0;j < 5;j++)
				cout.write (standard[i][j])<<" ";
		}
		cout << endl;
	}
	else
		cout<<"-------------"<<endl;
}

void Standard:: RoomsOccupied()
{
	cout << endl << endl;
}
void Standard:: display()
{
	cout << endl << endl;
}
int Standard::counter = 0;
int main()
{
	Standard ob;
	ob.add();
}*/