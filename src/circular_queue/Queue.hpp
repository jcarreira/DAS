/*
 * Circular queue
 */


#ifndef _DAS_QUEUE_H_
#define _DAS_QUEUE_H_

#include <string>

template<class T>
class Queue {
    public:
        Queue(uint64_t queue_address) : address(queue_address), queue_data_size(QUEUE_SIZE) {
            build_queue();
        }

        void enqueue(const T&);
        void dequeue();
        T tail() const;

        bool is_empty() const;
        int size() const;
        
        void build_queue();

    private:
        static const int QUEUE_SIZE = 1024;

        uint64_t address;
        T* queue_data;

        int queue_data_size;
        int queue_head; // requests added to the head
        int queue_tail; // requests removed from the queue
};

#endif // _DAS_QUEUE_H_

