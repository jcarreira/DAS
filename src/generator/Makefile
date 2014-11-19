CXXFLAGS = -Wall -O3
CXX      = g++
INCLUDES = -I../circular_queue -I..

all: generator

generator: generator.o
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(@) $^

%.o:%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $(@) $^

clean:
	rm -f *.o *~ generator
