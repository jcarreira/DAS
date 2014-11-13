#ifndef _QUEUE_H_
#define _QUEUE_H_

namespace DAS {
    namespace QueueLayer {

        template<class T>
        class Queue {
            public:
                void enqueue(const T&);
                void dequeue();
                T& tail();

            private:
                void build_queue();

                T* queue_data;
                int queue_size;
        };
    } // DAS
} // Queue

#endif // _QUEUE_H_
