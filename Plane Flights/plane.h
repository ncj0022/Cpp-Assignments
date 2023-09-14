class Plane{
	public:
		//Mutators
		void SetMake(string planeMake);
		void SetModel(string planeModel);
		void SetTailNumber(string planeTailNumber);
		void SetNumOfSeats(int planeSeats);
		void SetRange(int planeRange);
		void SetStatus(string planeStatus);

		//Accessors
		string GetMake();
		string GetModel();
		string GetTailNumber();
		int GetNumOfSeats();
		int GetRange();
		string GetStatus();

		//Default constructor
		Plane();

	private:
		string make;
		string model;
		string tailNumber;
		int seats;
		int range;
		string status;
};
