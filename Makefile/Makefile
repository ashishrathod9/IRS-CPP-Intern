CXX = g++
CXXFLAGS = -Wall -std=c++17
TARGET = program
OBJECTS = main.o math_utils.o

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

main.o: main.cpp math_utils.h
	$(CXX) $(CXXFLAGS) -c main.cpp

math_utils.o: math_utils.cpp math_utils.h
	$(CXX) $(CXXFLAGS) -c math_utils.cpp

clean:
	del *.o $(TARGET).exe

.PHONY: clean