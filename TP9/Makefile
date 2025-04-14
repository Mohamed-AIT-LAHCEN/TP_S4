CXX = g++
CXXFLAGS = -Wall -std=c++17

SRCS = Account_Util.cpp Account.cpp Checking_Account.cpp Savings_Account.cpp Trust_Account.cpp main.cpp 
OBJS = $(SRCS:.cpp=.o)
TARGET = Account_program

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean 