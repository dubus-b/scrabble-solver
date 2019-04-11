#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

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

bool compareLen(const std::string &a, const std::string &b)
{
    return (a.size() > b.size());
}

bool compareScore(const std::string &a, const std::string &b)
{
    return (get_string_score(a) > get_string_score(b));
}

class Dictionnary
{
  public:
    Dictionnary(const std::string &filename)
    {
        std::string line;
        std::ifstream myfile(filename);
        if (myfile.is_open())
        {
            std::cout << "Chargement du dictionnaire en mémoire..." << std::endl;
            while (getline(myfile, line))
                dict.push_back(line);
            std::sort(dict.begin(), dict.end(), compareScore);
            myfile.close();
        }
        else
            std::cerr << "Impossible d'ouvrir le fichier " << filename << std::endl;
    }
    ~Dictionnary()
    {
    }

    void print_solution()
    {
        std::cout << "Voici la liste des mots issues de la recherche dans le dictionnaire." << std::endl;
        for(auto word : solution)
            std::cout << word << " (" << word.size() << ") lettres et " << get_string_score(word) << " points" << std::endl;
    }

    void get_longest_word(const std::string &word)
    {
        int count = 0;
        bool is_a_solution;
        for (auto wd : dict)
        {
                is_a_solution = match(wd, word);
                if (is_a_solution)
                {
                    solution.push_back(wd);
                    if((solution.size() == 10))
                    {
                        std::cout << count << " essais ont été effectués pour trouver la solution" << std::endl;
                        return;
                    }
                }
                count += 1;
        }
    }
    bool match(const std::string &current, std::string word)
    {
        int i = 0;
        while (current[i] != '\0')
        {
            if (word.find(current[i]) == std::string::npos) {
                return false;
            }
            else
                word.erase(std::remove( word.begin(), word.end(), current[i] ), word.end());
            i++;
        }
        return true;
    }

  private:
    std::vector<std::string> dict;
    std::vector<std::string> solution;
};