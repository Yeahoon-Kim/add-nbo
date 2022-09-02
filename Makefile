#Makefile
CC = g++
CFLAGS = -W -Wall
OBJECTS = main.o
TARGET = add-nbo

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

$(OBJECTS): main.cpp

clean:
	rm -f *.o
	rm -f $(TARGET)

.PHONY: all clean