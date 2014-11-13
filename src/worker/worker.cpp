/*
 * Worker implementation
 */

#include "Queue.hpp"
#include "Request.hpp"

int main(int argc, char* argv[]) {

    uint64_t address = (uint64_t)0x08048034; // who knows?
    Queue<Request> queue(address);

    while(!queue.empty()) {
        Message m = queue.tail();
        queue.dequeue();
    }

    return 0;
}

