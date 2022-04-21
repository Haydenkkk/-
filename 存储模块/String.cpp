//This is a string less lagier than cstring
#include"String.h"

String::String(const char *s):_str(new char[strlen(s)+1])
{
    strcpy(_str, s);
    _size=strlen(s);
    _capacity=_size;

}

String::String(const String &theString):_str(new char[theString._capacity+1])
{
    strcpy(_str, theString._str);
    _size=theString._size;
    _capacity=theString._capacity;
}

int String::size() const
{
    return _size;
}

void String::clear()
{
    _size=0;
    _str[0]='\0';
}

void String::reserve(size_t cap)
{
    if(cap>_capacity){
        char *t_str=new char[cap+1];
        strcpy(t_str, _str);
        delete[] _str;
        _str=t_str;
        _capacity=cap;
    }
}

void String::push_back(char ch)
{
    if(_size==_capacity){
        if(_capacity==0){
            reserve(20);
        }else{
            reserve(2*_capacity);
        }
    }
    _str[_size]=ch;
    ++_size;
    _str[_size+1]='\0';
}

char String::pop_back()
{
    if(_size==0) return '\0';
    char rch=_str[_size-1];
    _str[_size-1]='\0';
    _size--;
    return rch;
}

void String::append(size_t n, char ch)
{
    for(size_t i=1;i<=n;i++){
        push_back(ch);
    }
}

void String::append(const char* str)
{
    size_t len=strlen(str);
    if(len+_size>_capacity){
        reserve((len+_size)*2);
    }
    strcpy(&_str[_size], str);
    _size+=len;
}

void String::append(const String &str)
{
    append(str._str);
}

String &String::operator=(const String &theString)
{
    if(&theString!=this){
        delete[] _str;
        _str=new char[theString._capacity+1];
        strcpy(_str, theString._str);
        _size=theString._size;
        _capacity=theString._capacity;
    }
    return *this;
}

String &String::operator=(const char *s)
{
    delete[] _str;
    size_t len=strlen(s);
    _str=new char[len+1];
    strcpy(_str, s);
    _size=len;
    _capacity=len;
    return *this;
}

String &String::operator+=(const String &theString)
{
    append(theString);
    return *this;
}

String &String::operator+=(const char *s)
{
    append(s);
    return *this;
}

String &String::operator+=(char ch)
{
    push_back(ch);
    return *this;
}

int String::compare(const String &theString) const
{
    return compare(theString._str);
}

int String::compare(const char *s) const
{
    const char *str1=_str-1;
    const char *str2=s-1;
    while(*++str1==*++str2&&*str1!=0);
    if(*str1>*str2) return 1;
    else if(*str1<*str2) return -1;
    else return 0;
}

bool String::operator==(const char *s) const
{
    if(compare(s)==0) return 1;
    else return 0;
}

bool String::operator==(const String &theString) const
{
    return operator==(theString._str);
}

bool String::operator>(const char *s) const
{
    if(compare(s)==1) return 1;
    else return 0;
}

bool String::operator>(const String &theString) const
{
    return operator>(theString._str);
}

bool String::operator<(const char *s) const
{
    if(compare(s)==-1) return 1;
    else return 0;
}

bool String::operator<(const String &theString) const
{
    return operator<(theString._str);
}

bool String::operator<=(const char *s) const
{
    return (operator<(s)||operator==(s));
}

bool String::operator<=(const String &theString) const
{
    return (operator<(theString._str)||operator==(theString._str));
}

bool String::operator>=(const char *s) const
{
    return (operator>(s)||operator==(s));
}

bool String::operator>=(const String &theString) const
{
    return (operator>(theString._str)||operator==(theString._str));
}

char String::operator[](size_t n) const
{
    return _str[n];
}

void String::insert(size_t pos, char ch)
{
    assert(pos<=_size);
    if(_size==_capacity){
        if(_capacity==0){
            reserve(20);
        }else{
            reserve(2*_capacity);
        }
    }
    size_t end=_size+1;
    while(end>=pos+1){
        _str[end]=_str[end-1];
        end--;
    }
    _str[pos]=ch;
    _size++;
}

void String::insert(size_t pos, const char *s)
{
    assert(pos<=_size);
    size_t len=strlen(s);
    if(_size+len>_capacity){
        reserve((_size+len)*2);
    }
    size_t end=_size+len;
    while(end>=pos+len){
        _str[end]=_str[end-len];
        end--;
    }
    while(*s) _str[pos++]=*s++;
    _size+=len;
}

void String::insert(size_t pos, String &theString)
{
    insert(pos, theString._str);
}

ssize_t String::find(char ch)
{
    for(int i=0;i<_size;i++){
        if(_str[i]==ch) return i;
    }
    return -1;
}

ssize_t String::find(String &theString)
{
    return find(theString._str);
}

void get_nextval(const char *s, ssize_t nextval[])
{
    ssize_t len=strlen(s);
    ssize_t j=-1, i=0;
    nextval[0]=-1;
    while(i<len){
        if(j==-1||s[i]==s[j]){
            ++i, ++j;
            if(s[i]!=s[j]) nextval[i]=j;
            else nextval[i]=nextval[j];
        }else{
            j=nextval[j];
        }
    }
}

ssize_t String::find(const char *s)
{
    ssize_t lenS=strlen(s);
    ssize_t lenT=strlen(_str);
    ssize_t next[lenS+1];
    get_nextval(s, next);
    ssize_t i=0, j=0;

    while(i<lenT&&j<lenS){
        if(j==-1||s[j]==_str[i]){
            ++j, ++i;
        }else{
            j=next[j];
        }
    }
     
    if(j>=lenS) return i-lenS;

    return -1;
   
}

iterator String::begin()
{
    return _str;
}

iterator String::end()
{
    return _str+_size;
}

const_iterator String::begin() const
{
    return _str;
}

const_iterator String::end() const
{
    return _str+_size;
}

String::~String()
{
    delete[] _str;
    _str = nullptr;
    _size = 0;
    _capacity = 0;
}

std::ostream &operator<<(std::ostream &_cout, const String &theString)
{
    _cout<<theString._str;
    return _cout;
}

std::istream &operator>>(std::istream &_cin, String &theString)
{
    char ch=_cin.get();
    while(ch!=' '&&ch!='\n'){
        theString+=ch;
        ch=_cin.get();
    }
    return _cin;
}

String operator+(const String &str, const char *s)
{
    String t_str=str;
    return t_str+=s;
}

String operator+(const char *s, const String &str)
{
    String t_str=s;
    return t_str+=str;
}

String operator+(const String &str1, const String &str2)
{
    String t_str=str1;
    return t_str+=str2;
}

//