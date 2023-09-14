
#include "plane.h"

class Planes {
	public:
		void AddPlane();
		void EditPlane();
		void DeletePlane();
		void SearchPlane();
		void PrintAllPlanes();
		void PrintPlaneInfo();
		Planes(){plane_count = 0; plane_cap = 0;}
	private:
		int plane_count;
		int plane_cap;
};
