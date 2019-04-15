#include "dictionary.hpp"

void menu(int &choice)
{
  std::cout << "Voulez-vous obtenir le mot le plus long ou le mot valant le maximum de point au Scrabble ?"
            << std::endl
            << "1 : Longueur " << std::endl
            << "2 : Valeur" << std::endl
            << "[1-2] ";
  std::cin >> choice;
  std::cin.clear();
  std::cin.ignore(1);
  if(std::cin.eof())
    choice = -1;
  if (choice != 1 && choice != 2 && choice != -1)
  {
        std::cerr << "Erreur : Veuillez réessayer" << std::endl;
        menu(choice);
  }
  return;
}

int main(int argc, char **argv)
{
  Dictionnary *dict;
  int choice;
  std::string solution;
  std::string word;
  if (argc < 2)
  {
    std::cout << "Usage : " << argv[0] << " dictionnaire" << std::endl;
    return 0;
  }
  else
  {
    menu(choice);
    if (choice == 1)
      dict = new Dictionnary(argv[1], false);
    else if (choice == 2)
      dict = new Dictionnary(argv[1], true);
    else
      return 0; // End of file
    std::cout << "Entrez le mot a tester : " << std::endl;
    std::cin >> word;
    dict->get_longest_word(word);
    dict->print_solution();
    delete dict;
    return 0;
  }
}
