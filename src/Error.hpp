#ifndef _ERROR_H_
#define _ERROR_H_

#include <string>

namespace DAS {
    class Error {
        public:
            Error(const std::string& error_msg) 
                : msg(error_msg)
            {}

            std::string str() const { 
                return msg;
            }

        private:
            std::string msg;
    };
}

#endif // _ERROR_H_


