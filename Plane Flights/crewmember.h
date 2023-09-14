#include <string>
using namespace std;

class CrewMember {
	public:
		void SetName(string memberName);
		void SetID(int memberID);
		void SetType(string memberType);
		void SetStatus(string memberStatus);

		//Accessors
		string GetName();
		int GetID();
		string GetType();
		string GetStatus();

		//Default constructor
		CrewMember();
	private:
		string name;
		int crewID;
		string type;
		string status;
};
