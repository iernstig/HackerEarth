CC = clang++
CFLAGS = -g -Wall -std=c++11

target = introduction
dependencies = comparison

all: introduction.o comparison.o
	$(CC) $(CFLAGS) -o intro comparison.o introduction.o

introduction.o : introduction.cpp
	$(CC) $(CFLAGS) -c $(target).cpp

comparison.o : comparison.cpp
	$(CC) $(CFLAGS) -c comparison.cpp
