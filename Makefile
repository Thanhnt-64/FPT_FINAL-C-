build: main.exe

main.exe: main.o sys.o user.o admin.o hotel.o room.o travel.o trans.o file.o
	g++ -o main.exe main.o sys.o user.o admin.o hotel.o room.o travel.o trans.o file.o

main.o: main.c++
	g++ -c main.c++ -o main.o
sys.o: System.c++
	g++ -c System.c++ -o sys.o
user.o:	User.c++
	g++ -c User.c++ -o user.o
admin.o: Admin.c++
	g++ -c Admin.c++ -o admin.o
hotel.o: Hotel.c++
	g++ -c Hotel.c++ -o hotel.o
room.o: Room.c++
	g++ -c Room.c++ -o room.o
travel.o: Travel.c++
	g++ -c Travel.c++ -o travel.o
trans.o: Transport.c++
	g++ -c Travel.c++ -o trans.o
file.o: File.c++
	g++ -c File.c++ -o file.o

clean:
	rm -f *.o
	rm -f *.exe