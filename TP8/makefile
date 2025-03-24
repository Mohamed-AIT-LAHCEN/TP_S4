CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

all: movie_tracker

movie_tracker: main.o Movie.o Movies.o
	$(CXX) $(CXXFLAGS) -o movie_tracker main.o Movie.o Movies.o

main.o: main.cpp Movies.h Movie.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Movies.o: Movies.cpp Movies.h Movie.h
	$(CXX) $(CXXFLAGS) -c Movies.cpp

Movie.o: Movie.cpp Movie.h
	$(CXX) $(CXXFLAGS) -c Movie.cpp

clean:
	rm -f *.o movie_tracker
