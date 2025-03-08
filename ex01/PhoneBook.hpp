#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8];
    int currentIndex;
    int totalContacts;

public:
    PhoneBook();
    void addContact(const Contact &contact);
    void searchContact() const;
    void displayContactList() const;
};

#endif
