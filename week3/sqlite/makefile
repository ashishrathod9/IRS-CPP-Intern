CXX = g++
CXXFLAGS = -Wall -std=c++11
LDFLAGS = -lsqlite3

program: main.o Database.o
	$(CXX) $(CXXFLAGS) main.o Database.o -o program $(LDFLAGS)

main.o: main.cpp Database.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Database.o: Database.cpp Database.h
	$(CXX) $(CXXFLAGS) -c Database.cpp

clean:
	rm -f *.o program users_unsafe.db users_safe.db

.PHONY: clean
