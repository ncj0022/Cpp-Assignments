#include "crewmember.h"

class CrewMembers {
	public:
		void AddCrewMember();
		void EditCrewMember();
		void DeleteCrewMember();
		void SearchCrewMember();
		void PrintAllCrewMembers();
		void PrintCrewMemberInfo();
		CrewMembers(){member_count = 0; member_cap = 0; memberlist = new CrewMember[20];}
		~CrewMembers(){delete[] memberlist;}
	private:
		CrewMember *memberlist;
		int member_count;
		int member_cap;
};
