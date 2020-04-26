#include "string1.h"
using namespace std;
String::String()
{
    str = new char{'\0'};
  // cout<<"Пустой конструктор "<<endl;
}
String::String(String& st):
str(st.str),length(st.length)
{

// cout<<" Конструктор копирования "<< str<<endl;

}
String::String(char st[])
{

  str  = new char[getLength(st)+1];
  int i = 0;
  for(;i<length;i++){
      str[i]=st[i];
  }
  str[i]='\0';
 // cout<<" Коснтруктор массива чаров "<<str<<endl;
}

template<class T>
int String::getLength(T * st){
    int i = 0;
    length = 0;
    while(st[i] !='\0'){
        length++;
        i++;
    }
    return  length;
}
String String::operator=(const String &st){

    if(this == &st)return *this;
    length = st.length;
    str  = st.str;
   //  cout<<" operator=String "<<str<<endl;
    return *this;
}
String String::operator=(const char * st){
   length = 0;
    str  = new char[getLength(st)+1];
   int i = 0;
   for(;i<length;i++){
       str[i]=st[i];
   }
   str[i]='\0';

   //  cout<<"operator = char[] "<<str<<endl;
    return *this;
}
String String::operator+(const String &str2){
  //   cout<<"Конконтация "<<str<<" "<<str2.str<<endl;
    String newStr;
    newStr.length =length+str2.length;
    newStr.str    = new char[newStr.length+1];
    int i = 0;
    for(; i<this->length;i++)
         newStr.str[i]=this->str[i];

    for(int j =0; j<str2.length;i++,j++)
         newStr.str[i]=str2.str[j];

     newStr.str[i]='\0';

     return newStr;
}
std::ostream& operator<< (std::ostream &out, const String &str){
    return out<<str.str;
}
std::istream& operator>> (std::istream& is,  String &str){
   is>>str.str;
    str.getLength(str.str);
    return is;
}

