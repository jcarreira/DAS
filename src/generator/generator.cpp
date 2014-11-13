/*
 * Generator implementation
 */

#include <Queue.hpp>
#include <Request.hpp>
#include <unistd.h>

using DAS::Request;

int main(int argc, char* argv[]) {

    uint64_t address = (uint64_t)0x08048034; // who knows?
    Queue<Request> queue(address);

    int request_id = 1;
    
    while (1) {
        queue.enqueue(Request(request_id++));
        usleep(500); // 0.5 seconds
    }
    
    return 0;
}

