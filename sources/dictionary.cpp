#include <algorithm> // sort
#include <fstream> // ifstream, getline
#include <iostream>
#include "dictionary.hpp"

int get_string_score(const std::string &str)
{
    int score = 0;
    for (auto c : str)
    {
        switch (c)
        {
        case 'a':
        case 'e':
        case 'i':
        case 'l':
        case 'n':
        case 'o':
        case 'r':
        case 's':
        case 't':
        case 'u':
        {
            score = score + 1;
            break;
        }
        case 'd':
        case 'g':
        case 'm':
        {
            score = score + 2;
            break;
        }
        case 'b':
        case 'c':
        case 'p':
        {
            score = score + 3;
            break;
        }
        case 'f':
        case 'h':
        case 'v':
        {
            score = score + 4;
            break;
        }
        case 'j':
        case 'q':
        {
            score = score + 8;
            break;
        }
        case 'k':
        case 'w':
        case 'x':
        case 'y':
        case 'z':
        {
            score = score + 10;
            break;
        }
        }
    }
    return score;
}

static bool compareLen(const std::string &a, const std::string &b)
{
    return (a.size() > b.size());
}

static bool compareScore(const std::string &a, const std::string &b)
{
    return (get_string_score(a) > get_string_score(b));
}

Dictionnary::Dictionnary(const std::string &filename, bool bonus)
{
    std::string line;
    std::ifstream myfile(filename);
    if (myfile.is_open())
    {
        std::cout << "Chargement du dictionnaire en mémoire..." << std::endl;
        while (getline(myfile, line))
            dict.push_back(line);
        if (bonus)
            std::sort(dict.begin(), dict.end(), compareScore);
        else
            std::sort(dict.begin(), dict.end(), compareLen);
        myfile.close();
    }
    else
        std::cerr << "Impossible d'ouvrir le fichier " << filename << std::endl;
}

void Dictionnary::print_solution()
{
  if (solution.size() == 0)
    {
      std::cout << "Aucun mot n'a été trouvé" << std::endl;
      return;
    }
  std::cout << "Voici la liste des mots issus de la recherche dans le dictionnaire." << std::endl;
  for (auto word : solution)
    std::cout << word << " " << word.size() << " lettres et " << get_string_score(word) << " points" << std::endl;
}

void Dictionnary::get_longest_word(const std::string &word)
{
    int count = 0;
    bool is_a_solution;
    for (auto wd : dict)
    {
        is_a_solution = match(wd, word);
        if (is_a_solution)
        {
            solution.push_back(wd);
        }
        count += 1;
	if (solution.size() == 1) // puisque le dictionnaire est trié, les solutions le sont aussi. limites a augmenter pour trouver plus de solutions :)
	  break;
    }
    std::cout << count << " essais ont été effectués pour trouver le mot solution : " << solution[0] << std::endl;
    return;
}

void Dictionnary::delete_used_letter(std::string &word, char c)
{
    std::string str;
    bool deleted = false;
    for (auto letter : word)
    {
        if (letter == c && deleted == false)
        {
            deleted = true;
        }
        else
        {
            str += letter;
        }
    }
    word = str;
}

bool Dictionnary::match(const std::string &current, std::string word)
{
    int i = 0;
    while (current[i] != '\0')
    {
        if (word.find(current[i]) == std::string::npos)
        {
            return false;
        }
        else
        {
            delete_used_letter(word, current[i]);
        }
        i++;
    }
    return true;
}
