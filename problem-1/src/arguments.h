#ifndef __ARGUMENTS_H__
#define __ARGUMENTS_H__

#include <string>

namespace arguments {
    typedef std::pair<long long, long long> range;
    struct allArguments {
        bool help = false;
        arguments::range range = {0, 1000};
    };
    arguments::range parseRange(std::string);
    arguments::allArguments parseArguments(int, char**);
}

#endif
