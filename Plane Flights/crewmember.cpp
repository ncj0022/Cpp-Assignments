#include <string>
using namespace std;

#include "crewmember.h"

//Default constructor
CrewMember::CrewMember(){
	name = "none";
	crewID = 0;
	type = "none";
	status = "none";
}


//Mutators
void CrewMember::SetName(string memberName) {
	name = memberName;
}

void CrewMember::SetID(int memberID) {
	crewID = memberID;
}

void CrewMember::SetType(string memberType) {
	type = memberType;
}

void CrewMember::SetStatus(string memberStatus) {
	status = memberStatus;
}

//Accessors
string CrewMember::GetName() {
	return name;
}

int CrewMember::GetID() {
	return crewID;
}

string CrewMember::GetType() {
	return type;
}

string CrewMember::GetStatus() {
	return status;
}
