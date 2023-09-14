#include "flight.h"

class Flights {
	public:
		void AddFlight();
		void DeleteFlight();
		void EditFlight();
		void SearchFlight();
		void PrintAllFlights();
		void PrintFlightInfo();
		Flights(){flight_count = 0; flight_cap = 0; flightlist = new Flight[20];}
		~Flights() {delete [] flightlist;}
	private:
		Flight *flightlist;
		int flight_count;
		int flight_cap;

};
