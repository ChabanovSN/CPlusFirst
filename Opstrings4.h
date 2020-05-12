#ifndef OPSTRINGS4_H
#define OPSTRINGS4_H
#include <string>
#include <vector>
#include <sstream>
#include<iostream>
using namespace std;
class Opstrings4
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
    static std::string rot(const std::string &strng){
        string str = strng;
        for(size_t i = 0,j=str.size()-1; i<str.size()/2;i++,j--)
            swap(str[i],str[j]);
        return str;
    }
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
    static std::string vertMirror(const std::string &strng){
        std::vector<std::string> words = spliter(strng);
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
public:
    static std::string diag2Sym(const std::string &strng){
        return vertMirror(rot90Counter(strng));
    }
    static std::string rot90Counter(const std::string &strng){
         return rot(rot90Clock(strng));
    }
    //string sol = "abcd|plhd|dhlp\nefgh|okgc|cgko\nijkl|njfb|bfjn\nmnop|miea|aeim";
    static std::string selfieDiag2Counterclock(const std::string &strng){
        vector<string> left = spliter(strng);
        vector<string> right = spliter(diag2Sym(strng));

        string newStr="";
        for(size_t j = 0; j < left.size();j++)
            newStr +=left[j]+"|"+right[j]+"\n";
        newStr = newStr.substr (0,newStr.size()-1);
        left = spliter(newStr);
        right=spliter(rot90Counter(strng));
     newStr="";
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
#endif // OPSTRINGS4_H
