#include"Opstrings1.h"
#include"Opstrings2.h"
#include"Opstrings3.h"
#include"Opstrings4.h"
#include<iostream>
#include <string>

class CodeSqStrings
{
public:
    static std::string code(const std::string &strng);
    static std::string decode(const std::string &strng);
};

int main()
{   string s =   "abcd\nefgh\nijkl\nmnop";
    string sol = "abcd|plhd|dhlp\nefgh|okgc|cgko\nijkl|njfb|bfjn\nmnop|miea|aeim";
    //s = "abcd\nefgh\nijkl\nmnop" -->
   // "abcd|aeim\nefgh|bfjn\nijkl|cgko\nmnop|dhlp"

    //diag_1_sym(s) => "aeim\nbfjn\ncgko\ndhlp"
    Opstrings4 p;
        cout<<sol<<endl;
                 cout<<"------------------"<<endl;
       cout<<p.oper(p.selfieDiag2Counterclock,s)<<endl;



    return 0;
}
