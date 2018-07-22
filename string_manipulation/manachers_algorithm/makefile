CC = clang++
CFLAGS = -g -std=c++11 -Wall

TARGET = manachers

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp

brute_force: palindromic_brute_force.cpp
	$(CC) $(CFLAGS) -o brute_force palindromic_brute_force.cpp

clean:
	$(RM) $(TARGET)
