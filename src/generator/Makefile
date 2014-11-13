CXXFLAGS = -Wall -O3
CXX      = g++
INCLUDES =-I../queue_object -I..

all: generator

generator: generator.o ../queue_object/Queue.o
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(@) $^

%.o:%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $(@) $^

clean:
	rm -f *.o *~
