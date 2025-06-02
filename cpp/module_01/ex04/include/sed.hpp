#ifndef SED_HPP
#define SED_HPP

#include <fstream>

class FileUtils {
public:
  FileUtils(const std::string &path);
  ~FileUtils(void);
  void debugMode(bool mode) { _debug = mode; }
  bool sed(std::string search, std::string replace);

private:
  const std::string _path;
  std::ifstream _file;
  std::ofstream _file_output;
  bool _debug;
};

#endif
