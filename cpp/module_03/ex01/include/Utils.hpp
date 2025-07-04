#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

#define RED "\033[31m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define GREEN "\033[32m"
#define DARKGREEN "\033[38;5;29m"
#define YELLOW "\033[33m"
#define MAGENTA "\033[35m"
#define RESET "\033[0m"

void msg(const std::string &text, std::string color = GREEN);
void banner(const std::string &text, std::string color = BLUE,
            int total_len = 54, char fillchar = '=');
#endif
