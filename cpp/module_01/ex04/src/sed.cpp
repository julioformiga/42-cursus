#include "sed.hpp"
#include <iostream>

FileUtils::FileUtils(const std::string &path) : _path(path), _debug(false) {
  if (_path.empty()) {
    throw std::runtime_error("File path is empty!");
  }
  _file.open(_path.c_str(), std::ifstream::in);
  if (!_file.is_open()) {
    throw std::runtime_error("File not found!");
  }
  if (_file.eof()) {
    _file.close();
    throw std::runtime_error("File is empty!");
  }
  _file_output.open((_path + ".replace").c_str(),
                    std::ofstream::out | std::ofstream::trunc);
  if (!_file_output.is_open()) {
    _file.close();
    throw std::runtime_error("Could not open output file");
  }
}

FileUtils::~FileUtils(void) {
  if (_file.is_open())
    _file.close();
  if (_file_output.is_open())
    _file_output.close();
}

bool FileUtils::sed(std::string search, std::string replace) {
  size_t n_times = 0;
  size_t line_number = 0;
  size_t pos = 0;
  std::string buffer;

  while (++line_number, std::getline(_file, buffer)) {
    pos = buffer.find(search);
    while (pos != std::string::npos) {
      buffer.erase(pos, search.length());
      buffer.insert(pos, replace);
      pos = buffer.find(search, pos + replace.length());
      n_times++;
    }
    if (_debug)
      std::cout << line_number << ": " << buffer << std::endl;
    _file_output << buffer << std::endl;
  }
  return (n_times);
}
