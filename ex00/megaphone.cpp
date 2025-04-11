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
