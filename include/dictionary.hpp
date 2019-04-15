#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

class Dictionnary
{
  public:
    Dictionnary(const std::string &filename, const bool & bonus);
    ~Dictionnary();
    void print_solution();
    void get_longest_word(const std::string &word);
    bool match(const std::string &current, std::string word);
  private:
    void delete_used_letter(std::string & word, const char &c);
    std::vector<std::string> dict;
    std::vector<std::string> solution;
};