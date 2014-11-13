#include "Queue.hpp"
#include <Error.hpp>

using DAS::Error;

template<class T>
void Queue<T>::enqueue(const T& t) {
    if (queue_head == queue_tail - 1
            || (queue_head == queue_data_size
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

template<class T>
void Queue<T>::build_queue() {
    queue_data = new T[QUEUE_SIZE];

    if (!queue_data)
        throw Error("Not enough memory");
}

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
