#include "PhoneBook.hpp"
#include "utils.hpp"
#include <iostream>
#include <string>
#include <limits>

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
