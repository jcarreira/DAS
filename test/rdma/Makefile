CXX=gcc
CXXFLAGS=-ggdb -Wall
LIBINCLUDES=-L/usr/lib
LIBS=-libverbs

all:
	$(CXX) $(CXXFLAGS) $(LIBINCLUDES) rdma_client.cpp $(LIBS) -o rdma_client
	$(CXX) $(CXXFLAGS) $(LIBINCLUDES) rdma_server.cpp $(LIBS) -o rdma_server

#        gcc -libverbs -Wall -I/usr/local/ofed/include -O2 -o rdma_client -L/usr/local/ofed/lib64 -L/usr/local/ofed/lib rdma_client.cpp
