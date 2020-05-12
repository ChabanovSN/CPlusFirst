#ifndef OPSTRINGS1_H
#define OPSTRINGS1_H
#include <string>
#include <vector>
#include <sstream>
using namespace std;
class Opstrings1
{
private:

public:
    static std::vector<std::string> split(const std::string &s,char c);
    static std::string vertMirror(const std::string &strng);
    static std::string horMirror(const std::string &strng);
    template<typename Func>
    static std::string oper(Func func, const std::string &s);

};

std::vector<std::string> Opstrings1::split(const std::string &s,char c = '\n')
{
    std::vector<std::string> out;
    std::istringstream ss(s);
    std::string next;
    while (std::getline(ss, next, c))
        out.push_back(next);
    return out;
}

std::string Opstrings1::vertMirror(const std::string &strng)
{
    std::vector<std::string> words = split(strng);
    std::string sb = "";
    for (unsigned int i = 0; i < words.size(); i++)
    {
        std::string word = words[i];
        for (int j = word.length() - 1; j >= 0; j--)
            sb += word[j];
        if (i < word.length() - 1)
            sb += "\n";
    }
    return sb;
}

std::string Opstrings1::horMirror(const std::string &strng)
{
  std::vector<std::string> words = split(strng);
    std::string sb = "";
  for (unsigned int i = words.size(); i >= 1; i--)
  {
    std::string word = words[i-1];
    sb += word;
    if (i > 1)
      sb += "\n";
  }
  return sb;
}

template<typename Func>
std::string Opstrings1::oper(Func func, const std::string &s)
{
    return func(s);
}


#endif // OPSTRINGS1_H
