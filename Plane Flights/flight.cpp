#include <string>
using namespace std;

#include "flight.h"

//Default constructor
Flight::Flight() {
	int planeID = 0;
	int pilotID = 0;
	int copilotID = 0;
	int crewMemberID = 0;
	string status = "none";
	int numOfPassengers = 0;
	string startTime = "none";
	string endTime = "none";
}

//Mutators
void Flight::SetPlaneID(int plane_ID) {
	planeID = plane_ID;
}

void Flight::SetPilotID(int pilot_ID) {
	pilotID = pilotID;
}

void Flight::SetCoPilotID(int copilot_ID) {
	copilotID = copilot_ID;
}

void Flight::SetCrewMemberID(int member_ID) {
	crewMemberID = member_ID;
}

void Flight::SetStatus(string flightStatus) {
	status = flightStatus;
}

void Flight::SetNumOfPassengers(int passengers) {
	numOfPassengers = passengers;
}

//Accessors
int Flight::GetPlaneID() {
	return planeID;
}

int Flight::GetPilotID() {
	return pilotID;
}

int Flight::GetCoPilotID() {
	return copilotID;
}

int Flight::GetCrewMemberID() {
	return crewMemberID;
}

string Flight::GetStatus() {
	return status;
}

int Flight::GetNumOfPassengers() {
	return numOfPassengers;
}

//Time Functions
void Flight::StartTime(string start) {
	startTime = start;
}

void Flight::EndTime(string end) {
	endTime = end;
}
