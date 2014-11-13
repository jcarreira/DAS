/*
 * Worker implementation
 */

#include "Queue.hpp"
#include "Request.hpp"

int main(int argc, char* argv[]) {

    DASQueue<Request> queue("service_queue");

    while(!queue.empty()) {
        Message m = queue.tail();
        queue.dequeue();
    }

    return 0;
}

