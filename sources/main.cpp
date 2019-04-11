#include "dictionary.hpp"

int main(int argc, char **argv)
{
  std::string solution;
  std::string word;
  if (argc == 2)
  {
    Dictionnary dictionnary(argv[1]);
    std::cout << "Entrez le mot a tester : " << std::endl;
    std::cin >> word;
    if (word.size() > 10)
    {
      return -1;
    }
    else
    {
      dictionnary.get_longest_word(word);
      dictionnary.print_solution();
    }
  }
}
