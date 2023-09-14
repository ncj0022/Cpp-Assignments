#include <string>
using namespace std;

#include "plane.h"

//Default constructor
Plane::Plane() {
	string make = "none";
	string model = "none";
	string tailNumber = "none";
	int seats = 0;
	int range = 0;
	string status = "none";
}

//Mutators
void Plane::SetMake(string planeMake) {
	make = planeMake;
}

void Plane::SetModel(string planeModel) {
	model = planeModel;
}

void Plane::SetTailNumber(string planeTailNumber) {
	tailNumber = planeTailNumber;
}

void Plane::SetNumOfSeats(int planeSeats) {
	seats = planeSeats;
}

void Plane::SetRange(int planeRange) {
	range = planeRange;
}

void Plane::SetStatus(string planeStatus) {
	status = planeStatus;
}

//Accessors
string Plane::GetMake() {
	return make;
}

string Plane::GetModel() {
	return model;
}

string Plane::GetTailNumber() {
	return tailNumber;
}

int Plane::GetNumOfSeats() {
	return seats;
}

int Plane::GetRange() {
	return range;
}

string Plane::GetStatus() {
	return status;
}
