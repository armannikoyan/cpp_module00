#include "include/Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

Contact::Contact(const Contact& other)
  : first_name_(other.first_name_)
  , last_name_(other.last_name_)
  , nickname_(other.nickname_)
  , phone_number_(other.phone_number_)
  , darkest_secret_(other.darkest_secret_) {}

Contact& Contact::operator=(const Contact& other) {
  if (this != &other) {
    first_name_ = other.get_first_name();
    last_name_ = other.get_last_name();
    nickname_ = other.get_nickname();
    phone_number_ = other.get_phone_number();
    darkest_secret_ = other.get_darkest_secret();
  }
  return *this;
}


const std::string& Contact::get_first_name() const { return first_name_; }
const std::string& Contact::get_last_name() const { return last_name_; }
const std::string& Contact::get_nickname() const { return nickname_; }
const std::string& Contact::get_phone_number() const { return phone_number_; }
const std::string& Contact::get_darkest_secret() const { return darkest_secret_; }

void  Contact::set_first_name(const std::string& first_name) { first_name_ = first_name; }
void  Contact::set_last_name(const std::string& last_name) { last_name_ = last_name; }
void  Contact::set_nickname(const std::string& nickname) { nickname_ = nickname; }
void  Contact::set_phone_number(const std::string& phone_number) { phone_number_ = phone_number; }
void  Contact::set_darkest_secret(const std::string& darkest_secret) { darkest_secret_ = darkest_secret; }
