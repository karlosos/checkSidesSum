#include "InputProcessor.h"

/**
 * Get input data and output results
 *
 * @param out
 * @param in
 */
void InputProcessor::process(std::ostream &out, std::istream &in) {
    int number_of_lines = getNumberOfTestCases(in);

    for (int i=0; i<number_of_lines; i++) {
        int number_of_chars = getSequencyLength(in);
        getSequence(number_of_chars, out, in);
    }

    printOutput(out);
}

/**
 * Specify number of test cases to check
 *
 * @param in
 * @return
 */
int InputProcessor::getNumberOfTestCases(std::istream &in) {
    std::string number_of_lines_str;
    std::getline(in, number_of_lines_str);
    int number_of_lines = std::stoi(number_of_lines_str);
    return number_of_lines;
}

/**
 * Determine the number of elements in a numerical sequence
 * 
 * @param in
 * @return
 */
int InputProcessor::getSequencyLength(std::istream &in) {
    std::string number_of_chars_str;
    std::getline(in, number_of_chars_str);

    int number_of_chars = std::stoi(number_of_chars_str);
    return number_of_chars;
}

/**
 * Get number sequence
 *
 * @param sequence_length
 * @param out
 * @param in
 */
void InputProcessor::getSequence(int sequence_length, std::ostream &out, std::istream &in) {
    std::string line;
    std::getline(in, line);

    while (line.length() < sequence_length) {
        out << "Sequence should have " << sequence_length << " elements." << std::endl;
        std::getline(in, line);
    }
    trimLine(sequence_length, line);
    input.push_back(line);
}

/**
 * Trim number sequence into given length
 *
 * @param sequence_length
 * @param line
 */
void InputProcessor::trimLine(int sequence_length, std::string &line) {
    if (line.length() > sequence_length) {
        line = line.substr(0, sequence_length);
        //out << line << std::endl;
    }
}

/**
 * Depending on isElementExisting for each case print "Yes" or "No"
 * @param out
 */
void InputProcessor::printOutput(std::ostream &out) {
    for (auto &i : input) {
        if (isElementExisting(i))
            out << "Yes" << std::endl;
        else
            out << "No" << std::endl;
    }
}

/**
 * Check if there is an element whose sum of elements on its left is equal to the sum of elements on its right side
 *
 * @param s
 * @return
 */
bool InputProcessor::isElementExisting(std::string s) {
    for (int i=0; i<s.length(); i++) {
        int sum_left = 0;
        int sum_right = 0;

        for (int j=0; j<i;j++) {
            sum_left += s.at(j) - '0';
        }

        for (int j=i+1; j<s.length();j++) {
            sum_right += s.at(j) - '0';
        }

        if (sum_left == sum_right)
            return true;
    }
    return false;
}