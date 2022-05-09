#include <iostream>
#include <stdexcept>
#include <string>

#include "messages.h"
#include "arguments.h"
#include "calculations.h"  

int main(int argc, char** argv) {
	if(argc > 2) {
        messages::print("Too many arguments.", true);
        messages::print(messages::TRYHELP_MSG);
	} else {
        try {
            arguments::allArguments parsedArgs = arguments::parseArguments(argc, argv);
            if (parsedArgs.help) {
                messages::print(messages::HELP_MSG);
            } else {
                messages::print(
                        std::string("Summary of all the multiples of 3 and 5 in range [") + std::to_string(parsedArgs.range.first) + "," + std::to_string(parsedArgs.range.second) + ") is equal to " + std::to_string(calculations::calcSum(parsedArgs.range)));
            }
        } catch (std::invalid_argument& e) {
            messages::print(std::string("Invalid argument: '") + e.what() + "'");
            messages::print(messages::TRYHELP_MSG);
        }
	}
	return 0;
}
