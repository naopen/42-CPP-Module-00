#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : currentIndex(0), totalContacts(0) {}

void PhoneBook::addContact(const Contact &contact)
{
    contacts[currentIndex] = contact;
    currentIndex = (currentIndex + 1) % 8;
    if (totalContacts < 8)
        totalContacts++;
}

void PhoneBook::displayContactList() const
{
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    std::cout << std::string(43, '-') << std::endl;

    for (int i = 0; i < totalContacts; i++)
    {
        std::string firstName = contacts[i].getFirstName();
        std::string lastName = contacts[i].getLastName();
        std::string nickname = contacts[i].getNickname();

        if (firstName.length() > 10)
            firstName = firstName.substr(0, 9) + ".";
        if (lastName.length() > 10)
            lastName = lastName.substr(0, 9) + ".";
        if (nickname.length() > 10)
            nickname = nickname.substr(0, 9) + ".";

        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << firstName << "|"
                  << std::setw(10) << lastName << "|"
                  << std::setw(10) << nickname << std::endl;
    }
}

void PhoneBook::searchContact() const
{
    if (totalContacts == 0)
    {
        std::cout << "Phonebook is empty!" << std::endl;
        return;
    }

    displayContactList();

    int index;
    std::cout << "\nEnter index to display: ";
    std::cin >> index;

    if (std::cin.fail() || index < 0 || index >= totalContacts)
    {
        std::cout << "Invalid index!" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return;
    }

    contacts[index].displayFull();
}
