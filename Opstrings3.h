#ifndef OPSTRINGS3_H
#define OPSTRINGS3_H
#include <string>
#include <vector>
#include <sstream>
#include<iostream>
using namespace std;

class Opstrings3
{
    static  std::vector<std::string> spliter(const std::string &s,char c='\n')
    {
        std::vector<std::string> out;
        std::istringstream ss(s);
        std::string next;
        while (std::getline(ss, next, c)){
            out.push_back(next);
        }
        return out;
    }
public:
    static string diag1Sym(const string &strng){
        string str = strng;
        vector<string> out= spliter(str);
        vector<string> reversOut;
        string newStr ="";
        for(size_t j = 0; j < out[0].size();j++){
            for(size_t i = 0 ;i < out.size();i++)
                newStr +=out[i][j];

            reversOut.push_back(newStr);
            newStr ="";
        }

        for( auto w : reversOut){
            newStr +=w+"\n";
        }
        return  newStr.substr (0,newStr.size()-1);
    }

    static std::string rot90Clock(const std::string &strng){
        string newStr = diag1Sym(strng);
        vector<string> out = spliter(newStr);
        for(size_t j = 0; j < out.size();j++){
            for(size_t i = 0, k =out[j].size()-1 ;i < out[j].size()/2;i++,k--){
                swap(out[j][i],out[j][k]);
            }

        }

        newStr="";
        for( auto w : out){
            newStr +=w+"\n";
        }
        return  newStr.substr (0,newStr.size()-1);

    }
    static std::string selfieAndDiag1(const std::string &strng){
        vector<string> left = spliter(strng);
        vector<string> right = spliter(diag1Sym(strng));

        string newStr="";
        for(size_t j = 0; j < left.size();j++)
            newStr +=left[j]+"|"+right[j]+"\n";
        return  newStr.substr (0,newStr.size()-1);
    }
    template<typename Func>
    static std::string oper(Func func, const std::string &s)
    {
        return func(s);
    }
};



#endif // OPSTRINGS3_H
