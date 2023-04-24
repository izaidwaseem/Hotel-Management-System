#include "Superior.h"
Superior::Superior()
{
	price = 1000;
	noOfRooms = 50;
	ifstream fin;
	int temp;
	fin.open("Rooms.txt");
	fin.seekg(209);
	for (int i = 0;i < 10;i++)
	{
		for (int j = 0;j < 5;j++)
		{
			fin >> temp;
			superior[i][j] = temp;
		}
	}
}
void Superior::add(ifstream& ob, Customer& obj, Customer* arr)    //CHecking in a room 
{
	if (obj.searchCustomer(ob,arr) == false)
		obj.newcustomer();
	else
		obj.checkin(ob,arr);
	int floorNo = 0, roomNo = 0, j = 0, k = 0;
	for (int i = 0;(superior[roomNo - 1][floorNo - 1] != 0) && (superior[roomNo - 1][floorNo - 1] != 2);i++)
	{
		if (i != 0)
		{
			cout << "Room is already reserved or occupied !" << endl << endl;
			floorNo = 0;
			roomNo = 0;
			k = 0;
			j = 0;
		}
		while (floorNo > 5 || floorNo == 0)
		{
			if (k != 0)
				cout << "Invalid floor number !" << endl << endl;
			cout << "Enter Floor No.(1-5) : ";
			cin >> floorNo;
			k++;
		}
		while (roomNo > 10 || roomNo == 0)
		{
			if (j != 0)
				cout << "Invalid Room number !" << endl << endl;
			cout << "Enter Room No.(1-10) : ";
			cin >> roomNo;
			j++;
		}
	}
	if (superior[roomNo - 1][floorNo - 1] == 0)
	{
		cout << "Room allotted !" << endl << endl;
		superior[roomNo - 1][floorNo - 1] = 1;
	}
	obj.setBalance(obj.getDays() * price);
	obj.setFloor(floorNo);
	obj.setroom(roomNo);
	obj.setType("Superior");
}
void Superior::reserve(ifstream& ob, Customer& obj, Customer* arr)   //reserving a room
{
	if (obj.searchCustomer(ob,arr) == false)
		obj.newcustomer();
	else
		obj.checkin(ob,arr);
	int floorNo = 0, roomNo = 0, j = 0, k = 0;
	for (int i = 0;(superior[roomNo - 1][floorNo - 1] != 0) && (superior[roomNo - 1][floorNo - 1] != 2);i++)
	{
		if (i != 0)
		{
			cout << "Room is already reserved or occupied !" << endl << endl;
			floorNo = 0;
			roomNo = 0;
			k = 0;
			j = 0;
		}
		while (floorNo > 5 || floorNo == 0)
		{
			if (k != 0)
				cout << "Invalid floor number !" << endl << endl;
			cout << "Enter Floor No.(1-5) : ";
			cin >> floorNo;
			k++;
		}
		while (roomNo > 10 || roomNo == 0)
		{
			if (j != 0)
				cout << "Invalid Room number !" << endl << endl;
			cout << "Enter Room No.(1-10) : ";
			cin >> roomNo;
			j++;
		}
	}
	if (superior[roomNo - 1][floorNo - 1] == 0)
	{
		cout << "Room allotted !" << endl << endl;
		superior[roomNo - 1][floorNo - 1] = 2;
	}
	obj.setBalance(obj.getDays() * price);
	obj.setFloor(floorNo);
	obj.setroom(roomNo);
	obj.setType("Superior");
}
void Superior::output(ofstream& ob)
{
	ob << "Superior" << endl;
	for (int i = 0;i < 10;i++)
	{
		for (int j = 0;j < 5;j++)
		{
			ob << (superior[i][j]);
			if (j != 4)
				ob << " ";
		}
		ob << endl;
	}
	ob << endl;
}
void Superior::display()
{
	int* temp = new int[5];
	int cnt = 0;
	for (int i = 0;i < 5;i++)
	{
		for (int j = 0;j < 10;j++)
		{
			if (superior[j][i] == 0)
				cnt++;
		}
		temp[i] = cnt;
		cnt = 0;
	}
	for (int i = 0;i < 5;i++)
	{
		cout << "Rooms Available on floor " << i + 1 << " : ";
		for (int j = 0;j < 10;j++)
		{
			if (superior[j][i] != 1 && superior[j][i] != 2)
			{
			
				cnt++;
				
			}
		}
		cout  << cnt << endl;
	
		cnt = 0;
	}
	delete[] temp;
	temp = NULL;
}
void Superior::RoomsOccupied()
{
	int* temp = new int[5];
	int cnt = 0;
	for (int i = 0;i < 5;i++)
	{
		for (int j = 0;j < 10;j++)
		{
			if (superior[j][i] == 2|| superior[j][i] == 1)
				cnt++;
		}
		temp[i] = cnt;
		cnt = 0;
	}
	for (int i = 0;i < 5;i++)
	{
		cout << " superior Rooms Occupied on floor " << i + 1 << " : ";
		for (int j = 0;j < 10;j++)
		{
			if (superior[j][i] != 0)
			{
				cout << j + 1;
				cnt++;
				if (cnt < temp[i])
					cout << ", ";
			}
		}
		cout << "\nTotal no. of reserved rooms = " << cnt << endl;
		cout << endl << endl;
		cnt = 0;
	}
	delete[] temp;
	temp = NULL;
}