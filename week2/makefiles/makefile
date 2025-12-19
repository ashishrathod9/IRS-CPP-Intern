app: main.o add.o
	g++ main.o add.o -o app

main.o: main.cpp add.h
	g++ -c main.cpp

add.o: add.cpp add.h
	g++ -c add.cpp

clean:
	rm -f *.o app
