/*
 * Generator implementation
 */

#include <Queue.hpp>
#include <Request.hpp>
#include <unistd.h>
#include <Error.hpp>
#include <iostream>
#include <stdlib.h>

using DAS::Request;
using DAS::Error;

int main(int argc, char* argv[]) {

    uint64_t address = (uint64_t)0x08048034; // who knows?
    Queue<Request> queue(address);

    try {

        int request_id = 1;

        while (1) {
            queue.enqueue(Request(request_id++));
            usleep(50); // 0.5 seconds
            std::cout << "Added one request" << std::endl;
        }

    } catch(Error& e) {
        std::cerr << "Catched exception: " << e.str() << std::endl;
        exit(-1);
    } catch(Error* e) {
        std::cerr << "Catched exception: " << e->str() << std::endl;
        exit(-1);
    }

    return 0;
}

