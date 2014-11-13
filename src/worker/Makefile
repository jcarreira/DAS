CFLAGS	= -Wall -O3
CXX = c++
INCLUDES=-I../queue_object

all: worker

worker: worker.o
	$(CXX) $(CXXFLAGS) -o $(@) $^

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c -o $(@) $^

clean:
	rm -f *.o *~
