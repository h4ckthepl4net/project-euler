#include "messages.h"

void messages::print(::messages::messages msgId, bool error) {
    std::ostream& out = (error) ? std::cerr : std::cout;
    out << ::messages::messagesArray[msgId] << std::endl;
}

void messages::print(const char * msg, bool error) {
    std::ostream& out = (error) ? std::cerr : std::cout;
    out << msg << std::endl;
}

void messages::print(std::string msg, bool error) {
    std::ostream& out = (error) ? std::cerr : std::cout;
    out << msg << std::endl;
}

const char * const ::messages::messagesArray[] = {
"DESCRIPTION\n\
        This tiny program is used\n\
        to get the sum of all the\n\
        multiples of 3 and 5.\n\
\n\
SYNOPSYS\n\
        ./problem-1 [OPTIONS]... [RANGE]...\n\
\n\
RANGE\n\
        When no range specified program\n\
        calculates the sum of all the\n\
        multiples of 3 and 5 from 0 to 1000.\n\
\n\
        [number]\n\
                Calculate sum below specified\n\
                number\n\
\n\
        [number1]-[number2]\n\
                Calculate sum starting from\n\
                number1 to number2\n\
\n\
OPTIONS\n\
        -?, --help\n\
                Output this help message.\n\
",
"Try '-?' or '--help' for more information."
};
