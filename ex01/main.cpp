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
    std::cout << "Enter command (ADD/SEARCH/EXIT): ";
    std::getline(std::cin, input);
    switch (getCommand(input))
    {
      case ADD:
        pb.add();
        break;
      case SEARCH:
        break;
      case EXIT:
        return (0);
      default:
        continue;
    }
  }
}
