#ifndef PASS_H
#define PASS_H
#include<iostream>
#include<iomanip>
using namespace std;
class Pass
{
public:
    Pass(){}
    Pass(string site,string pass){
       setSite(site);
       setPass(pass);
    }
   string getPass() const{
       return pass;
    }
   void setPass(string str){
      pass = new char(str.size());
       copy(str.begin(),str.end(),pass);
   }
   string getSite() const{
       return site;
    }
   void setSite(string str){
      site = new char(str.size());
      copy(str.begin(),str.end(),site);
   }
//   ~Pass(){
//       delete pass;
//       delete site;
//   }
private:
  char * pass;
  char * site;
};

#endif // PASS_H
