#pragma once

#include <iostream>
#include <cctype>

#include "Contact.hpp"

#define MAX_CONTACT_SIZE 8

class PhoneBook {
  private:
    Contact contacts_[MAX_CONTACT_SIZE];
    unsigned short index_;

    bool isValidName(const std::string& name);
    bool isValidNickname(const std::string& nickname);
    bool isValidPhoneNumber(const std::string& phone_number);

  public:
    PhoneBook();
    ~PhoneBook();
    PhoneBook(const PhoneBook&);
    PhoneBook& operator=(const PhoneBook&);

    void add();
    void search();
};
