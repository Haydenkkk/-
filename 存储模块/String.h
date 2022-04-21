#ifndef STRING_H 
#define STRING_H
#include<iostream>
#include<string.h>
#include<assert.h>
typedef char * iterator;
typedef const char * const_iterator;

class String
{
public:
    String(const char *s="");
    String(const String &theString);

    String &operator=(const String &theString);
    String &operator=(const char *s);

    String &operator+=(const String &theString);
    String &operator+=(const char *s);
    String &operator+=(char ch);

    int compare(const char *s) const;
    int compare(const String &theString) const;
    bool operator==(const char *s) const;
    bool operator==(const String &theString) const;
    bool operator>(const char *s) const;
    bool operator>(const String &theString) const;
    bool operator<(const char *s) const;
    bool operator<(const String &theString) const;
    bool operator<=(const char *s) const;
    bool operator<=(const String &theString) const;
    bool operator>=(const char *s) const;
    bool operator>=(const String &theString) const;

    char operator[](size_t n) const;

    int size() const;
    void clear();
    void push_back(char ch);
    char pop_back();

    void insert(size_t pos, char ch);
    void insert(size_t pos, const char *s);
    void insert(size_t pos, String &theString);

    void append(size_t, char ch);
    void append(const char *str);
    void append(const String &str);

    ssize_t find(char ch);
    ssize_t find(const char *s);
    ssize_t find(String &theString);

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

    ~String();

    friend std::ostream &operator<<(std::ostream &_cout, const String &theString);
    friend std::istream &operator>>(std::istream &_cin, String &theString);

private:
    void reserve(size_t cap);
    char *_str=nullptr;
    int _size=0;
    int _capacity=0;
};

std::ostream &operator<<(std::ostream &_cout, const String &theString);
std::istream &operator>>(std::istream &_cin, String &theString);

String operator+(const String &str, const char *s);
String operator+(const char *s, const String &str);
String operator+(const String &str1, const String &str2);
//
#endif