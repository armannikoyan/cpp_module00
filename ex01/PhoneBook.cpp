/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:32:24 by anikoyan          #+#    #+#             */
/*   Updated: 2025/04/22 21:57:33 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/PhoneBook.hpp"

PhoneBook::PhoneBook()
  : index_(0)
  , is_full_(false) {}
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
    is_full_ = other.is_full_;

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
      std::cout << "Error: Phone Number cannot be empty and must contain only numbers.\n";
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

  contacts_[index_] = contact;
  if (++index_ == MAX_CONTACT_SIZE && !is_full_)
    is_full_ = true;
  index_ %= MAX_CONTACT_SIZE;
}

std::string PhoneBook::truncate(const std::string& str) {
    if (str.length() > MAX_COLUMN_SIZE) {
        std::string truncated = str.substr(0, MAX_COLUMN_SIZE - 1);
        truncated += ".";
        return truncated;
    }
    return str;
}

static bool is_numberic(const std::string& str)
{
  for (size_t i = 0; i < str.length(); ++i)
    if (!std::isdigit(str[i]))
      return false;
  return true;
}

void PhoneBook::search()
{
  int index;
  std::string input;

  if (!is_full_ && index_ == 0)
  {
    std::cout << "No contacts found in the phonebook\n";
    return;
  }
  else 
  {
    std::cout << "|" << std::setw(MAX_COLUMN_SIZE) << "Index"
      << "|" << std::setw(MAX_COLUMN_SIZE) << "First Name"
      << "|" << std::setw(MAX_COLUMN_SIZE) << "Last Name"
      << "|" << std::setw(MAX_COLUMN_SIZE) << "Nickname" << "|\n";
    for (unsigned short i = 0; (is_full_ && i < MAX_CONTACT_SIZE) || (i < index_); ++i)
    {
      std::cout << "|" << std::setw(MAX_COLUMN_SIZE) << i
        << "|" << std::setw(MAX_COLUMN_SIZE) << truncate(contacts_[i].get_first_name())
        << "|" << std::setw(MAX_COLUMN_SIZE) << truncate(contacts_[i].get_last_name())
        << "|" << std::setw(MAX_COLUMN_SIZE) << truncate(contacts_[i].get_nickname()) << "|\n";
    }
  }

  do
  {
    std::cout << "\nEnter index of the entry: ";
    std::getline(std::cin, input);
    if (input.empty())
      std::cout << "Error: Index cannot be empty.\n";
    else if (!is_numberic(input))
      std::cout << "Index can contain only positive numbers.\n";
  } while (input.empty() || !is_numberic(input));

  index = std::atoi(input.data());
  if ((!is_full_ && index >= index_) || (is_full_ && index > MAX_CONTACT_SIZE))
  {
    std::cout << "Error: No contact found with this index.\n";
    return;
  }

  std::cout << "|" << std::setw(MAX_COLUMN_SIZE) << truncate("First Name")
    << "|" << std::setw(MAX_COLUMN_SIZE) << truncate("Last Name")
    << "|" << std::setw(MAX_COLUMN_SIZE) << truncate("Nickname")
    << "|" << std::setw(MAX_COLUMN_SIZE) << truncate("Darkest Secret")
    << "|\n";
  std::cout << "|" << std::setw(MAX_COLUMN_SIZE) << truncate(contacts_[index].get_first_name())
    << "|" << std::setw(MAX_COLUMN_SIZE) << truncate(contacts_[index].get_last_name())
    << "|" << std::setw(MAX_COLUMN_SIZE) << truncate(contacts_[index].get_nickname())
    << "|" << std::setw(MAX_COLUMN_SIZE) << truncate(contacts_[index].get_darkest_secret())
    << "|\n";
}
