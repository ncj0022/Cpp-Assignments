proj: main.o flights.o planes.o crewmembers.o
	gcc -o main.o flights.o planes.o crewmembers.o

main.o: main.cpp planes.h  crewmembers.h
	gcc -c main.cpp

planes.o: planes.cpp planes.h
	gcc -c planes.cpp 

crewmembers.o: crewmembers.cpp crewmembers.h
	gcc -c crewmembers.cpp 

flights.cpp: flights.h
	gcc -c flights.h

planes.cpp: planes.h 
	gcc -c planes.h 

crewmembers.cpp: crewmembers.h 
	gcc -c crewmembers.h

flights.h: flight.h 
	gcc -c flight.h

planes.h: plane.h
	gcc -c plane.h

crewmembers.h: crewmember.h
	gcc -c crewmember.h
