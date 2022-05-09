#ifndef __MESSAGES_H__
#define __MESSAGES_H__

#include <iostream>
#include <string>

namespace messages {
    enum messages {
        HELP_MSG,
        TRYHELP_MSG
    };
    extern const char * const messagesArray[];
    void print(::messages::messages, bool = false);
    void print(const char *, bool = false);
    void print(std::string, bool = false);
}

#endif
