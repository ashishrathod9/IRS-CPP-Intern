CXX = g++
CXXFLAGS = -Wall -std=c++11

program: main2.o Student.o
	$(CXX) $(CXXFLAGS) main2.o Student.o -o program

program: main.o circle.o
	$(CXX) $(CXXFLAGS) main.o circle.o -o program

main2.o: main2.cpp Student.h
	$(CXX) $(CXXFLAGS) -c main2.cpp

main.o: main.cpp circle.h
	$(CXX) $(CXXFLAGS) -c main.cpp



Student.o: Student.cpp Student.h
	$(CXX) $(CXXFLAGS) -c Student.cpp

circle.o: circle.cpp circle.h
	$(CXX) $(CXXFLAGS) -c circle.cpp

clean:
	rm -f *.o program
