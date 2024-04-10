build: main.exe

main.exe: main.o sys.o user.o admin.o hotel.o room.o travel.o trans.o file.o
	g++ -o main.exe main.o sys.o user.o admin.o hotel.o room.o travel.o trans.o file.o

main.o: main.cpp
	g++ -c main.cpp
clean:
	rm -f *.o
	rm -f *.exe