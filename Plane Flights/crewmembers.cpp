#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string>
using namespace std;

#include "crewmembers.h"

const int size = 2;

void CrewMembers::AddCrewMember() {

	string name;
	int crewID;
	string type;
	string status;

	if(member_count == member_cap)
	{
		CrewMember *temp;
		temp = new CrewMember[member_cap+size];
		for(int i = 0; i < member_count; i++)
		{
			temp[i] = memberlist[i];
			delete[] memberlist;
			member_cap+=size;
			memberlist = temp;
		}
	}

	printf("Enter crew members name(first and last): ");
	cin >> name;
	printf("Enter crew members id: ");
	cin >> crewID;
	printf("Enter crew members type: ");
	cin >> type;
	printf("Enter crew members status(in, out, or sick): ");
	cin >> status;

	memberlist[member_count].SetName(name);
	memberlist[member_count].SetID(crewID);
	memberlist[member_count].SetType(type);
	memberlist[member_count].SetStatus(status);
}

void CrewMembers::SearchCrewMember() {
}

void CrewMembers::EditCrewMember() {
}

void CrewMembers::DeleteCrewMember() {
}

void CrewMembers::PrintAllCrewMembers() {
}

void CrewMembers::PrintCrewMemberInfo() {
}

