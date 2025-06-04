#include "Harl.hpp"
#include <iostream>

void Harl::debug(void) {
  std::cout << "\033[1;36m"
            << "[  DEBUG ]\nI love having extra bacon for my "
               "7XL-double-cheese-triple-pickle-special-ketchup burger.\n"
               "I really do !\n"
            << "\033[0m" << std::endl;
}

void Harl::info(void) {
  std::cout
      << "\033[1;34m"
      << "[  INFO ]\nI cannot believe adding extra bacon costs more money.\n"
         "You didn’t put enough bacon in my burger! If you did, I wouldn’t "
         "be asking for more!\n"
      << "\033[0m" << std::endl;
}

void Harl::warning(void) {
  std::cout
      << "\033[1;33m"
      << "[  WARNING ]\nI think I deserve to have some extra bacon for "
         "free.\nI’ve been coming for years, whereas you started working here "
         "just last month.\n"
      << "\033[0m" << std::endl;
}

void Harl::error(void) {
  std::cout << "\033[1;31m"
            << "[  ERROR ]\nThis is unacceptable! I want to speak to the "
               "manager now.\n"
            << "\033[0m" << std::endl;
}

void Harl::complain(std::string level) {
  std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  void (Harl::*funcs[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning,
                                  &Harl::error};
  for (int i = 0; i < 4; ++i) {
    if (levels[i] == level) {
      for (int n = i; n < 4; ++n)
        (this->*funcs[n])();
      return;
    }
  }
  std::cout << "[ Probably complaining about insignificant problems ]"
            << std::endl;
}
