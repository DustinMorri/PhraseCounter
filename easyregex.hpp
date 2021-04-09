#ifndef easyregex_hpp
#define easyregex_hpp
#endif
#include <deque>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
std::string fileToString(std::string file);
std::deque<std::deque<std::string>> findAll(std::string s,std::regex e);