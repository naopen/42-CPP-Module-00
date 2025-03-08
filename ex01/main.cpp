#include "PhoneBook.hpp"
#include <iostream>
#include <string>

std::string getInput(const std::string &prompt)
{
    std::string input;
    do {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (std::cin.eof())
            exit(0);
    } while (input.empty());
    return input;
}

int main()
{
    PhoneBook phoneBook;
    std::string command;

    while (true)
    {
        std::cout << "\nEnter command (ADD, SEARCH, or EXIT): ";
        std::getline(std::cin, command);

        if (std::cin.eof() || command == "EXIT")
            break;

        if (command == "ADD")
        {
            Contact newContact;
            std::string firstName = getInput("\nEnter first name: ");
            std::string lastName = getInput("Enter last name: ");
            std::string nickname = getInput("Enter nickname: ");
            std::string phoneNumber = getInput("Enter phone number: ");
            std::string darkestSecret = getInput("Enter darkest secret: ");

            newContact.setContact(firstName, lastName, nickname,
                                phoneNumber, darkestSecret);
            phoneBook.addContact(newContact);
            std::cout << "\nContact added successfully!" << std::endl;
        }
        else if (command == "SEARCH")
        {
            phoneBook.searchContact();
        }
    }

    return 0;
}
