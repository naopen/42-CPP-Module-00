#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <limits>
#include <cctype>
#include <cstdlib> // std::exit

// エラーメッセージの定義
namespace ErrorMessage {
    const std::string EMPTY_FIELD = "Field cannot be empty. Please try again.";
    const std::string INVALID_PHONE_FORMAT = "Invalid phone number format. Please use digits, spaces, and hyphens only.";
    const std::string INVALID_COMMAND = "Invalid command. Please use ADD, SEARCH, or EXIT.";
    const std::string INPUT_TERMINATED = "Input terminated. Exiting program.";
}

// 入力を取得し、EOFまたは空文字列の場合はプログラムを終了
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

// 電話番号のバリデーション
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

// コマンドの取得と実行
void processCommand(PhoneBook &phoneBook, const std::string &command) {
    if (command == "ADD") {
        Contact newContact;
        std::string firstName = getInputOrExit("Enter first name: ");
        std::string lastName = getInputOrExit("Enter last name: ");
        std::string nickname = getInputOrExit("Enter nickname: ");

        std::string phoneNumber;
        do {
            phoneNumber = getInputOrExit("Enter phone number: ");
        } while (!isValidPhoneNumber(phoneNumber));

        std::string darkestSecret = getInputOrExit("Enter darkest secret: ");

        newContact.setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
        phoneBook.addContact(newContact);
        std::cout << "Contact added successfully!" << std::endl;
    } else if (command == "SEARCH") {
        phoneBook.searchContact();
    } else if (command != "EXIT") {
        std::cout << ErrorMessage::INVALID_COMMAND << std::endl;
    }
}

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "\nEnter command (ADD, SEARCH, or EXIT): ";
        if (!std::getline(std::cin, command)) {
            std::cout << std::endl << ErrorMessage::INPUT_TERMINATED << std::endl;
            break;
        }

        if (command == "EXIT") {
            break;
        }
        processCommand(phoneBook, command);
    }

    return 0;
}