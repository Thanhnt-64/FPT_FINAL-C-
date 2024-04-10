build: main.exe

main.exe: main.o sys.o user.o admin.o hotel.o room.o travel.o trans.o file.o
	g++ -o main.exe main.o sys.o user.o admin.o hotel.o room.o travel.o trans.o file.o

main.o: main.cpp
	g++ -c main.cpp -o main.o
sys.o: System.cpp
	g++ -c System.cpp -o sys.o
user.o:	User.cpp
	g++ -c User.cpp -o user.o
admin.o: Admin.cpp
	g++ -c Admin.cpp -o admin.o
hotel.o: Hotel.cpp
	g++ -c Hotel.cpp -o hotel.o
room.o: Room.cpp
	g++ -c Room.cpp -o room.o
travel.o: Travel.cpp
	g++ -c Travel.cpp -o travel.o
trans.o: Transport.cpp
	g++ -c Transport.cpp -o trans.o
file.o: File.cpp
	g++ -c File.cpp -o file.o

clean:
	rm -f *.o
	rm -f *.exe