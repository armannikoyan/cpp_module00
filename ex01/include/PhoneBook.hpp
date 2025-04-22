/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:32:09 by anikoyan          #+#    #+#             */
/*   Updated: 2025/04/22 14:32:10 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cctype>
#include <iomanip>
#include <limits>
#include <cstdlib>

#include "Contact.hpp"

#define MAX_CONTACT_SIZE 8
#define MAX_COLUMN_SIZE 10

class PhoneBook {
  private:
    Contact contacts_[MAX_CONTACT_SIZE];
    unsigned short index_;
    bool is_full_;

    bool isValidName(const std::string& name);
    bool isValidNickname(const std::string& nickname);
    bool isValidPhoneNumber(const std::string& phone_number);

    std::string truncate(const std::string& str);

  public:
    PhoneBook();
    ~PhoneBook();
    PhoneBook(const PhoneBook&);
    PhoneBook& operator=(const PhoneBook&);

    void add();
    void search();
};
