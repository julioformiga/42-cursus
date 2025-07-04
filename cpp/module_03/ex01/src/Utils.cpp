#include "Utils.hpp"
#include <iostream>

void msg(const std::string &text, std::string color) {
  std::cout << color << text << RESET << std::endl;
}

void banner(const std::string &text, std::string color, int total_len,
            char fillchar) {
  int text_len = text.length();
  int side_space = total_len - text_len - 2;

  if (side_space < 0) {
    std::cout << text << std::endl;
    return;
  }

  int left_width = side_space / 2;
  int right_width = side_space % 2;

  std::cout << color << std::string(left_width + right_width, fillchar) << " "
            << text << " " << std::string(left_width, fillchar) << RESET
            << std::endl;
}
