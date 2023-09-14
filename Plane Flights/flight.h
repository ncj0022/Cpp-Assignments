#include <string>
using namespace std;

#include "plane.h"
#include "crewmember.h"

class Flight {
	public:
		//Mutators
		void SetPlaneID(int plane_id);
		void SetPilotID(int pilot_id);
		void SetCoPilotID(int copilot_id);
		void SetCrewMemberID(int member_id);
		void SetStatus(string flightStatus);
		void SetNumOfPassengers(int passengers);

		//Accessors
		int GetPlaneID();
		int GetPilotID();
		int GetCoPilotID();
		int GetCrewMemberID();
		string GetStatus();
		int GetNumOfPassengers();

		void StartTime(string start);
		void EndTime(string end);

		//Default constructor
		Flight();
	private:
		int planeID;
		int pilotID;
		int copilotID;
		int crewMemberID;
		string status;
		int numOfPassengers;
		string startTime;
		string endTime;
};
