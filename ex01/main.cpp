#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <limits>
#include <cctype>

std::string getInput(const std::string &prompt)
{
    std::string input;
    do {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (std::cin.eof())
			return "";
        if (input.empty())
            std::cout << "Field cannot be empty. Please try again." << std::endl;
    } while (input.empty());
    return input;
}

bool isValidPhoneNumber(const std::string &number, std::string &errorMessage)
{
    if (number.empty()) {
        errorMessage = "Phone number cannot be empty.";
        return false;
    }

    for (std::string::size_type i = 0; i < number.length(); ++i) {
        char c = number[i];
        if (!std::isdigit(c) && c != '-' && c != ' ') {
            errorMessage = "Invalid phone number format. Please use digits, spaces, and hyphens only.";
            return false;
        }
    }

    errorMessage = ""; // エラーなし
    return true;
}

int main()
{
    PhoneBook phoneBook;
    std::string command;

    while (true)
    {
        std::cout << "\nEnter command (ADD, SEARCH, or EXIT): ";
        if (!std::getline(std::cin, command))
        {
            std::cout << "\nInput terminated. Exiting program." << std::endl;
            break;
        }

        if (command == "EXIT")
            break;

        if (command == "ADD")
        {
            Contact newContact;
            std::string firstName = getInput("Enter first name: ");
            std::string lastName = getInput("Enter last name: ");
            std::string nickname = getInput("Enter nickname: ");

            std::string phoneNumber;
            std::string errorMessage;
            do {
                phoneNumber = getInput("Enter phone number: ");
                if (!isValidPhoneNumber(phoneNumber, errorMessage))
                    std::cout << errorMessage << std::endl;
            } while (!isValidPhoneNumber(phoneNumber, errorMessage));

            std::string darkestSecret = getInput("Enter darkest secret: ");

            newContact.setContact(firstName, lastName, nickname,
                                phoneNumber, darkestSecret);
            phoneBook.addContact(newContact);
            std::cout << "Contact added successfully!" << std::endl;
        }
        else if (command == "SEARCH")
        {
            phoneBook.searchContact();
        }
        else if (!command.empty())
        {
            std::cout << "Invalid command. Please use ADD, SEARCH, or EXIT." << std::endl;
        }
    }

    return 0;
}
