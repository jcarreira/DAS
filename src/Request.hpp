#ifndef _QUEUE_H_
#define _QUEUE_H_

namespace DAS {
    class Request {
        public:
            Request(int id = -1) : request_id(id) {
            }

            int getRequestId() const;

        private:
            int request_id;
    };
}


#endif // _QUEUE_H_
