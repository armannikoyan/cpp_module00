#include "include/PhoneBook.hpp"

PhoneBook::PhoneBook()
  : index_(0) {}
PhoneBook::~PhoneBook() {}

PhoneBook::PhoneBook(const PhoneBook& other)
{
  *this = other;
}

PhoneBook& PhoneBook::operator=(const PhoneBook& other)
{
  if (this != &other)
  {
    index_ = other.index_;

    for(unsigned short i = 0; i <= other.index_; ++i)
      contacts_[i] = other.contacts_[i];
  }
  return *this;
}

bool PhoneBook::isValidName(const std::string& name)
{
  if (name.empty()) return false;
  for (size_t i = 0; i < name.length(); ++i)
    if (!std::isalpha(name[i])) return false;
  return true;
}

bool PhoneBook::isValidNickname(const std::string& nickname)
{
  if (nickname.empty()) return false;
  for (size_t i = 0; i < nickname.length(); ++i)
    if (!std::isalnum(nickname[i])) return false;
  return true;
}

bool PhoneBook::isValidPhoneNumber(const std::string& phone_number)
{
  if (phone_number.empty()) return false;
  for (size_t i = 0; i < phone_number.length(); ++i)
    if (!std::isdigit(phone_number[i])) return false;
  return true;
}

void PhoneBook::add()
{
  Contact contact;
  std::string input;

  do
  {
    std::cout << "Enter First Name: ";
    std::getline(std::cin, input);
    if (!isValidName(input))
      std::cout << "Error: Name cannot be empty and must contain only letters.\n";
  } while (!isValidName(input));
  contact.set_first_name(input);

  do
  {
    std::cout << "Enter Last Name: ";
    std::getline(std::cin, input);
    if (!isValidName(input))
      std::cout << "Error: Last Name cannot be empty and must contain only letters.\n";
  } while (!isValidName(input));
  contact.set_last_name(input);

  do
  {
    std::cout << "Enter Nickname: ";
    std::getline(std::cin, input);
    if (!isValidNickname(input))
      std::cout << "Error: Nickname cannot be empty and must contain only letters and numbers.\n";
  } while (!isValidNickname(input));
  contact.set_nickname(input);

  do
  {
    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, input);
    if (!isValidPhoneNumber(input))
      std::cout << "Error: Phone Number cannot be empty and must contain only letters and numbers.\n";
  } while (!isValidPhoneNumber(input));
  contact.set_phone_number(input);

  do
  {
    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, input);
    if (input.empty())
      std::cout << "Error: Darkest Secret cannot be empty.\n";
  } while (input.empty());
  contact.set_darkest_secret(input);

  contacts_[index_++ % MAX_CONTACT_SIZE] = contact;
}

void PhoneBook::search() {
}
