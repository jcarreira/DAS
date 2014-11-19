/*
 * Circular queue
 */


#ifndef _DAS_QUEUE_H_
#define _DAS_QUEUE_H_

#include <string>
#include <Error.hpp>
#include <stdint.h>

using DAS::Error;

template<class T>
class Queue {
    public:
        Queue(uint64_t queue_address) 
            : address(queue_address), queue_data_size(QUEUE_SIZE), 
            queue_head(0), queue_tail(0)
        {
            build_queue_data();
        }

        void enqueue(const T&);
        void dequeue();
        T tail() const;

        bool is_empty() const;
        int size() const;
        
//        void build_queue();
//template<class T>
        void build_queue_data() {
            queue_data = new T[QUEUE_SIZE];

            if (!queue_data)
                throw DAS::Error("Not enough memory");
        }

    private:
        static const int QUEUE_SIZE = 1024;

        uint64_t address;
        T* queue_data;

        int queue_data_size;
        int queue_head; // requests added to the head
        int queue_tail; // requests removed from the queue
};

template<class T>
void Queue<T>::enqueue(const T& t) {
    if (queue_head == queue_tail - 1
            || (queue_head == (queue_data_size - 1)
                && queue_tail == 0))
        throw new Error("Queue is full");

    queue_data[queue_head] = t;

    queue_head++;
    if (queue_head == queue_data_size) // overflow
        queue_head = 0; 
}

template<class T>
T Queue<T>::tail() const {
    if (is_empty())
        throw Error("Queue is empty");

    return queue_data[queue_tail];
}

template<class T>
void Queue<T>::dequeue() {
    queue_tail++;
}

//template<class T>
//void Queue<T>::build_queue() {
//    queue_data = new T[QUEUE_SIZE];
//
//    if (!queue_data)
//        throw Error("Not enough memory");
//}

template<class T>
int Queue<T>::size() const {
    if (queue_head >= queue_tail)
        return queue_head - queue_tail;
    else return queue_head + (queue_data_size - queue_tail);
}

template<class T>
bool Queue<T>::is_empty() const {
    return size() == 0;
}


#endif // _DAS_QUEUE_H_

