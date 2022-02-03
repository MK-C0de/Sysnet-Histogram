CXX = g++
CXXFLAGS = -std=c++11 -Wall -pthread -lrt -ftest-coverage -fprofile-arcs

OBJECTS = histogram.o

mt-collatz: mt-collatz.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY : clean
clean:
	$(RM) *.o *.gc*
