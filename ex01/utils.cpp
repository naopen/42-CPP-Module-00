#include "utils.hpp"
#include <iostream>
#include <cstdlib>
#include <cctype>

std::string getInputOrExit(const std::string &prompt) {
    std::string input;
    std::cout << prompt;
    if (!std::getline(std::cin, input)) {
        std::cout << std::endl << ErrorMessage::INPUT_TERMINATED << std::endl;
        std::exit(EXIT_SUCCESS); // または EXIT_FAILURE
    }
    if (input.empty()) {
        std::cout << ErrorMessage::EMPTY_FIELD << std::endl;
        return getInputOrExit(prompt); // 再帰的に入力を求める
    }
    return input;
}

bool isValidPhoneNumber(const std::string &number) {
    if (number.empty()) {
        std::cout << ErrorMessage::EMPTY_FIELD << std::endl;
        return false;
    }
    for (std::string::size_type i = 0; i < number.length(); ++i) {
        char c = number[i];
        if (!std::isdigit(c) && c != '-' && c != ' ') {
            std::cout << ErrorMessage::INVALID_PHONE_FORMAT << std::endl;
            return false;
        }
    }
    return true;
}

bool isValidNumber(const std::string &str) {
    if (str.empty())
        return false;

    for (std::string::size_type i = 0; i < str.length(); ++i) {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}
