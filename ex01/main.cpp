/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:32:32 by anikoyan          #+#    #+#             */
/*   Updated: 2025/04/22 14:32:33 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/PhoneBook.hpp"

enum Command { ADD, SEARCH, EXIT, INVALID };

Command getCommand(const std::string& input)
{
  if (input == "ADD") return ADD;
  if (input == "SEARCH") return SEARCH;
  if (input == "EXIT") return EXIT;
  return INVALID;
}

int main()
{
  PhoneBook pb;
  std::string input;

  while (true)
  {
    do
    {
      std::cout << "Enter command (ADD/SEARCH/EXIT): ";
      if (!std::getline(std::cin, input))
      {
        if (std::cin.eof())
          return 0;
      }
    } while (input.empty());

    switch (getCommand(input))
    {
      case ADD:
        pb.add();
        break;
      case SEARCH:
        pb.search();
        break;
      case EXIT:
        return 0;
      default:
        continue;
    }

    std::cout << "\n";
  }
}
