#
#  Makefile for Architecture Explorer
#
#  by Alan Su, NCKU
#  alansuphd@mail.ncku.edu.tw
#

CC = g++
PCFLAG = -O1 -Wall -c
POFLAG = -O1 -Wall
SRC = Node.h List.h main.cpp
OBJ = main.o
TARGET = list

all:$(TARGET)
Node.o: Node.h
	$(CC) $(PCFLAG) $(@:.o=.cpp)
List.o: List.h 
	$(CC) $(PCFLAG) $(@:.o=.cpp)
main.o: main.cpp
	$(CC) $(PCFLAG) $(@:.o=.cpp)
$(TARGET): $(OBJ)
	$(CC) $(POFLAG) $(LIB) $(OBJ) -o $@

clean:
	rm $(OBJ)
	rm $(TARGET)

