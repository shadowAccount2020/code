#include "mystring.h"


mystring::mystring (const char * p) //构造器
{
    if(p == nullptr)
    {
        _str = new char[1];
        *_str = '\0';
    }
    else
    {
        _str = new char [strlen(p)+1];
        strcpy(_str,p);
    }
}

mystring::~mystring ()//析构器
{
    delete[]_str;
}

mystring::mystring(const mystring & another)//拷贝构造器
{
    _str = new char [strlen(another._str) + 1];
    strcpy(_str,another._str);
}
mystring& mystring::operator=(const mystring & another)//赋值运算符重载
{
    if(this == &another)
    {
        return *this;
    }
    else
    {
        delete []this->_str;
        _str = new char[strlen(another._str)+1];
        strcpy(_str,another._str);
        return *this;
    }
}

bool mystring::operator < (const mystring & another)
{
    return strcmp(_str,another._str) < 0;
}

bool mystring::operator > (const mystring & another)
{
    return strcmp(_str,another._str) > 0;
}

bool mystring::operator == (const mystring & another)
{
    return strcmp(_str,another._str) == 0;
}

bool mystring::operator >= (const mystring & another)
{
    return strcmp(_str,another._str) >= 0;
}

bool mystring::operator <= (const mystring & another)
{
    return strcmp(_str,another._str) <= 0;
}

mystring mystring::operator + (const mystring & another)
{
    int len = strlen( _str) + strlen(another._str);
    mystring ms;
    delete []ms._str;
    ms._str = new char[len+1]{0};//这里的{0}一定要写，不然乱码
    strcat(strcat(ms._str,_str),another._str);

    return ms;
}

mystring& mystring::operator += (const mystring & another)
{
    int catlen = strlen(this->_str);
    int srclen = strlen(another._str);
    int len = catlen + srclen;
    this -> _str = static_cast<char *>(realloc(this->_str,len + 1));
    memset(this->_str + catlen, 0 , srclen);
    strcat(this->_str , another._str);
    return *this;
}

ostream & operator<< (ostream & co, const mystring& ms)
{
    co << ms._str << endl;
    return co;
}

istream & operator>> (istream & ci,  mystring& ms)
{
    delete [] ms._str;
    char c[1024] = {0};

    cin >> c;
    ms._str = new char[strlen(c)+1];
    strcpy(ms._str,c);

    return ci;
}

char mystring::operator[](int n)
{
    return _str[n];
}

char mystring::at(int n)
{
    return _str[n];
}

char * mystring::c_str()
{
    return _str;
}
