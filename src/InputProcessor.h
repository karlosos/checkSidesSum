#ifndef HEX_INPUTPARSER_H
#define HEX_INPUTPARSER_H

#include <vector>
#include <string>
#include <iostream>

class InputProcessor {
private:
    std::vector<std::string> input;
    int getNumberOfTestCases(std::istream &in);
    int getSequencyLength(std::istream &in);
    void printOutput(std::ostream &out);
    void getSequence(int sequence_length, std::ostream &out, std::istream &in);
    void trimLine(int sequence_length, std::string &s);

public:
    void process(std::ostream &out = std::cout, std::istream &in = std::cin) ;
    bool isElementExisting(std::string);
};


#endif //HEX_INPUTPARSER_H
