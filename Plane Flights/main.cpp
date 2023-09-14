//Name: Nicholas Jones
//Email: Nicholasjones5@my.unt.edu
//Description: This program is used to manage Mean Green Airline flights.

#include <iostream>
#include <string>
using namespace std;

#include "planes.h"
#include "crewmembers.h"

void PrintMenu() {
	cout << "Choose an option: " << endl;
	cout << "a - Add a plane " << endl;
	cout << "b - Add a  crew member" << endl;
	cout << "c - Add a flight" << endl;
	cout << "d - Search a plane " << endl;
	cout << "e - Search a crew member " << endl;
	cout << "f - Search a flight " << endl;
	cout << "q - Quit" << endl;
	cout << endl;
}

int main() {

	cout << "Nicholas Jones" << endl;
	cout << "CSCE 1040" << endl;
	cout << "Homework 4" << endl;
	cout << "Nicholasjones5@my.unt.edu\n" << endl;

	char option;

	//class objects
	Planes tempPlane;
	CrewMembers tempMember;
//	Flights tempFlight;

	PrintMenu();
	cin >> option;

	while(option != 'q') {
		switch(option) {
			case 'a':
				tempPlane.AddPlane();
				PrintMenu();
				cin >> option;
				break;
			case 'b':
				tempMember.AddCrewMember();
				PrintMenu();
				cin >> option;
				break;
			case 'c':
				break;
			case 'd':
				tempPlane.SearchPlane();
				PrintMenu();
				cin >> option;
			case 'q':
				cout << endl;
				break;
			default:
				break;
		}
	}

	return 0;

}
