CXX = g++
CXXFLAGS = -Wall -std=c++11

all: main

main: main.cpp ex1_calculator.cpp ex2_inventory.cpp ex3_stack.cpp
	$(CXX) $(CXXFLAGS) -o main main.cpp ex1_calculator.cpp ex2_inventory.cpp ex3_stack.cpp

clean:
	rm -f main

.PHONY: all clean 