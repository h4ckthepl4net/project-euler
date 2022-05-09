#include "arguments.h"

arguments::range arguments::parseRange(std::string argument) {
    arguments::range range = { 0, 1000 };
    std::string::size_type nextCharIndex;
    long long number1 = 1000, number2 = 0;
    number1 = std::stoll(argument, &nextCharIndex, 10);
    if(nextCharIndex != argument.length()) {
        if(argument[nextCharIndex++] == '-') {
            argument = argument.substr(nextCharIndex);
            number2 = std::stoll(argument, &nextCharIndex, 10);
            if(nextCharIndex != argument.length()) {
                throw std::exception();
            }
        } else {
            throw std::exception();
        }
    }
    range.first = std::min(number1, number2);
    range.second = std::max(number1, number2);
    return range;
}

arguments::allArguments arguments::parseArguments(int argc, char** argv) {
    bool rangeSet = false;
    arguments::allArguments args;
    for(char i = 1; i < argc; i++) {
        std::string argument = argv[i];
        if(argument == "-?" ||
           argument == "--help") {
            args.help = true;
            return args;
        } else {
            if (!rangeSet) {
                try {
                    args.range = parseRange(argv[i]);
                    rangeSet = true;
                } catch (std::exception&) {
                    throw std::invalid_argument(argument);
                }
            } else {
                throw std::invalid_argument(argument);
            }
        }
    }
    return args;
}
