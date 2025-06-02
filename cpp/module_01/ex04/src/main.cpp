#include "sed.hpp"
#include <iostream>

int main(int argc, char **argv) {
  if (argc != 4) {
    std::cout << ("Usage: ./replace <filepath> <search> <replace>")
              << std::endl;
    return (1);
  }

  try {
    FileUtils file(argv[1]);
    file.debugMode(0);
    file.sed(argv[2], argv[3]);
  } catch (const std::exception &e) {
    std::cout << "Error: " << e.what() << std::endl;
    return (1);
  }
  return (0);
}
