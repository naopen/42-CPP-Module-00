#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

// 定数として定義
namespace Config {
    const int MAX_CONTACTS = 8;
    const int DISPLAY_WIDTH = 10;
}


PhoneBook::PhoneBook() : currentIndex(0), totalContacts(0) {}

// 電話帳に連絡先を追加
void PhoneBook::addContact(const Contact &contact) {
    contacts[currentIndex] = contact;
    currentIndex = (currentIndex + 1) % Config::MAX_CONTACTS;
    if (totalContacts < Config::MAX_CONTACTS) {
        totalContacts++;
    }
}

// 文字列を指定された幅に切り詰める関数
std::string truncateString(const std::string& str, std::string::size_type width) {
    if (str.length() > width) {
        return str.substr(0, width - 1) + ".";
    }
    return str;
}

// 電話帳のリストを表示
void PhoneBook::displayContactList() const {
    std::cout << std::setw(Config::DISPLAY_WIDTH) << "Index" << "|"
              << std::setw(Config::DISPLAY_WIDTH) << "First Name" << "|"
              << std::setw(Config::DISPLAY_WIDTH) << "Last Name" << "|"
              << std::setw(Config::DISPLAY_WIDTH) << "Nickname" << std::endl;
    std::cout << std::string(4 * Config::DISPLAY_WIDTH + 3, '-') << std::endl;

    for (int i = 0; i < totalContacts; i++) {
        std::string firstName = truncateString(contacts[i].getFirstName(), Config::DISPLAY_WIDTH);
        std::string lastName = truncateString(contacts[i].getLastName(), Config::DISPLAY_WIDTH);
        std::string nickname = truncateString(contacts[i].getNickname(), Config::DISPLAY_WIDTH);

        std::cout << std::setw(Config::DISPLAY_WIDTH) << i << "|"
                  << std::setw(Config::DISPLAY_WIDTH) << firstName << "|"
                  << std::setw(Config::DISPLAY_WIDTH) << lastName << "|"
                  << std::setw(Config::DISPLAY_WIDTH) << nickname << std::endl;
    }
}

// 電話帳の検索
void PhoneBook::searchContact() const {
    if (totalContacts == 0) {
        std::cout << "Phonebook is empty!" << std::endl;
        return;
    }

    displayContactList();

    int index;
    std::cout << "\nEnter index to display: ";
    std::cin >> index;

    if (std::cin.fail() || index < 0 || index >= totalContacts) {
        std::cout << "Invalid index!" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    // index入力後の不要な改行を無視
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    contacts[index].displayFull();
}