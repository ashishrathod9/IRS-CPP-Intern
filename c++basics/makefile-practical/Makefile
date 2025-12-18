CC=g++
CFLAGS=-Wall -O2
SRC=main.cpp add.cpp multiply.cpp
OBJ=$(SRC:.cpp=.o)
TARGET=app

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) $(TARGET)
