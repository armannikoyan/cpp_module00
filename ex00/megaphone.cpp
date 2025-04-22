/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:31:53 by anikoyan          #+#    #+#             */
/*   Updated: 2025/04/22 14:31:54 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
  if (argc <= 1)
  {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return (0);
  }

  for (int row = 1; row < argc; ++row)
  {
    std::string line(argv[row]);
    for (size_t i = 0; i < line.length(); ++i)
      line[i] = std::toupper(line[i]);
    std::cout << line;
  }
  std::cout << std::endl;
  return (0);
}
