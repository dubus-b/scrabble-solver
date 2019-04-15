#ifndef DICTIONARY_HPP_
# define DICTIONARY_HPP_

#include <vector>
#include <string>

class Dictionnary
{
  public:
    Dictionnary(const std::string &filename, bool bonus);
    ~Dictionnary() = default;
    void print_solution();
    void get_longest_word(const std::string &word);
    bool match(const std::string &current, std::string word);
  private:
    void delete_used_letter(std::string & word, char c);
    std::vector<std::string> dict;
    std::vector<std::string> solution;
};

#endif /* !DICTIONARY_HPP_ */
