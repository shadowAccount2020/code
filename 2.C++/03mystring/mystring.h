#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
#include <string.h>

using  namespace std;
class mystring
{
public:
    mystring (const char * p = nullptr);
    ~mystring ();
    mystring(const mystring & another);
    mystring& operator=(const mystring & another);
    bool operator < (const mystring & another);
    bool operator > (const mystring & another);
    bool operator == (const mystring & another);
    bool operator >= (const mystring & another);
    bool operator <= (const mystring & another);

    mystring operator + (const mystring & another);
    mystring& operator += (const mystring & another);

    friend ostream & operator << (ostream & co, const mystring& ms);
    friend istream  & operator >> (istream & ci,  mystring& ms);

    char operator[](int n);
    char at(int n);
    char * c_str();

private:
    char * _str;
};

#endif // MYSTRING_H
