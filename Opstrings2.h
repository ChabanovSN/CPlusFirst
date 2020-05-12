#ifndef OPSTRINGS2_H
#define OPSTRINGS2_H
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Opstrings2
{
   static  std::vector<std::string> spliter(const std::string &s,char c='\n')
    {
        std::vector<std::string> out;
        std::istringstream ss(s);
        std::string next;
        while (std::getline(ss, next, c))
            out.push_back(next);
        return out;
    }
public:
    static std::string rot(const std::string &strng){
        string str = strng;
        for(size_t i = 0,j=str.size()-1; i<str.size()/2;i++,j--)
            swap(str[i],str[j]);
        return str;
    }
    static std::string selfieAndRot(const std::string &strng){
        string left = strng;
              vector<string> split = spliter(left);
              string result = "";
              for( auto w : split){
                  string s(w.size(),'.');
                  result +=w+s+"\n";
              }
              string right = rot(result.substr (0,result.size()-1));
        return result+"\n"+right;
    }

    template<typename Func>
    static std::string oper(Func func, const std::string &s)
    {
        return func(s);
    }
};


#endif // OPSTRINGS2_H
