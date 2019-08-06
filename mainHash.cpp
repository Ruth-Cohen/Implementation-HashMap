//========================================
//name: Rut Goldshtain and Rut Spanyer
//id:315556951 - 316213164
//targil:2
//teacher: Adina Milston
//========================================
#include <iostream>
#include <string>
#include "Hash.h"

int main(){
	int size;
	int choice;
	int ind;
	string stationName, stationCode;
	cout << "enter size of professional's hash table:\n ";
	cin >> size;
	Hash<string,string> hP(size);

	
	do{
		cout << "to add a new station enter 1\n";
		cout << "to delete a station enter 2\n";
		cout << "to search for a station given a code enter 3\n";
		cout << "to exit enter 10\n";
		cin >> choice;

		switch (choice){
		case 1:cout << "Please enter code and name "; 
			   cin >> stationCode >> stationName;
			   hP.insert(stationCode, stationName);
			break;
		case 2:
		    cout << "Please enter code ";
			cin >> stationCode;
			hP.deleteI(stationCode);
			break;
		case 3:
			cout << "Please enter code ";
			cin >> stationCode;
			ind = hP.search(stationCode);
			if (ind >= 0)
				cout << "The name of " << stationCode << " is " << *hP.value(ind) << endl;
			else
				cout << "code " << stationCode << " does not exist " << endl;
			break;
		case 10:cout << "Bye Bye";//exit
			break;
		default:
			break;
		}

	} while (choice != 10);

	return 0;
}