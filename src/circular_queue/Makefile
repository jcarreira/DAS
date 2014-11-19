CXX      = g++
CXXFLAGS = -Wall -O3
INCLUDES = -I..

all: Queue.o

%.o:%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $^

clean:
	rm -rf *.o
