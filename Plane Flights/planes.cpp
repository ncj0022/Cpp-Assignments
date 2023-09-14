#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <vector>
using namespace std;

#include "planes.h"

vector<Plane> planelist;

void Planes::AddPlane() {

	string make;
	string model;
	string tailNumber;
	int seats;
	int range;
	string status;

	Plane temp;

	printf("Enter plane make: ");
	cin >> make; cin.ignore();
	printf("Enter plane model: ");
	cin >> model; cin.ignore();
	printf("Enter plane tail number: ");
	cin >> tailNumber; cin.ignore();
	printf("Enter number of seats on plane: ");
	cin >> seats; cin.ignore();
	printf("Enter range of plane: ");
	cin >> range; cin.ignore();
	printf("Enter plane's status(in, out, repair): ");
	cin >> status; cin.ignore();

	temp.SetMake(make);
	temp.SetModel(model);
	temp.SetTailNumber(tailNumber);
	temp.SetNumOfSeats(seats);
	temp.SetRange(range);
	temp.SetStatus(status);

	planelist.push_back(temp);

}

void Planes::SearchPlane() {

	int choice;
	int num;
	string search;

	cout << "Pick a criteria to search for: 1-make, 2-model, 3-tail number, 4-Number of seats, 5-Range, 6-status." << endl;
	cin >> choice;

	switch(choice) {
		case 1:
			cout << "What is the make?" << endl;
			cin >> search; cin.ignore();
			for(int i = 0; i < planelist.size(); i++)
			{
				Plane temp;
				temp = planelist.at(i);
				if(search == temp.GetMake()) {
					cout << "Found Plane" << endl;
				}
				else {
					cout << "Plane not found" << endl;
				}
			}
			break;
		case 2:
			cout << "What is the model?" << endl;
			cin >> search; cin.ignore();
			for(int i = 0; i < planelist.size(); i++)
			{
				Plane temp;
				temp = planelist.at(i);
				if(search == temp.GetModel()){
					cout << "Found Plane" << endl;
				}
			}
			break;
		case 3:
			cout << "What is the tail number?" << endl;
			cin >> search; cin.ignore();
			for(int i = 0; i < planelist.size(); i++)
			{
				Plane temp;
				temp = planelist.at(i);
				if(search == temp.GetTailNumber()) {
					cout << "Found Plane" << endl;
				}
				else {
					cout << "Plane not found" << endl;
				}
			}
		case 4:
			cout << "What is the number of seats?" << endl;
			cin >> num; cin.ignore();
			for(int i = 0; i < planelist.size(); i++) 
			{
				Plane temp;
				temp = planelist.at(i);
				if(num == temp.GetNumOfSeats()) {
					cout << "Found Plane" << endl;
				}
				else {
					cout << "Plane not found" << endl;
				}
			}
		case 5:
			cout << "What is the range of the plane?" << endl;
			cin  >> num; cin.ignore();
			for(int i = 0; i<planelist.size(); i++)
			{
				Plane temp;
				temp = planelist.at(i);
				if(num == temp.GetRange()) {
					cout << "Found Plane" << endl;
				}
				else {
					cout << "Plane not found" << endl;
				}
			}
		case 6:
			cout << "What is the status of the plane?" << endl;
			cin >> search; cin.ignore();
			for(int i = 0; i < planelist.size(); i++) 
			{
				Plane temp;
				temp = planelist.at(i);
				if(search == temp.GetStatus()) {
					cout << "Found Plane" << endl;
				}
				else {
					cout << "Plane not found" << endl;
				}
			}
		default:
			break;
	}
}

void Planes::EditPlane() {;

}

void Planes::DeletePlane() {
}

void Planes::PrintAllPlanes() {
}

void Planes::PrintPlaneInfo() {
}


