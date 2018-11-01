//
// Created by jmaharja on 11/1/18.
//

#ifndef BST_STRING_H
#define BST_STRING_H

#endif //BST_STRING_H
#include <iostream>

class string{
private:
    char* str;
    int size;

public:
    string();
    string(const string& newStr);
    string(char* chars);
    ~string();
    int length() const;
    int capacity() const;
    void operator +(const string& str1);
};

string :: string()
{
    str = new char[129];
    size = 128;
    for (int i = 0; i <= size; ++i) {
        str[i] = '\0';
    }
}

int string::length() const {
    for (int i = 0; i < size; ++i) {
        if(str[i] == '\0') return i;
    }
    return size;
}

int string::capacity() const {
    return size;
}

string::string(char* chars) {
    int i = 0;
    while (chars[i] != '\0') {
         i++;
    }
    std::cout << i<< std::endl;
    str = new char[i];
    str = chars;
    size = i;
}

string::~string() {
    delete []str;
    size = 0;
}
/*
friend string* string::operator+(const string &str1, const string& str2) {
    size =  str1.length() + str2.length();
    str = new char[size];
    int i;
    for (i = 0; i < str1.length(); ++i) {
        str[i] = str1.str[i];
    }
    for (int j = 0; j < str2.length(); ++j, ++i) {
        str[i] = str2.str[j];
    }
    return this;
}*/

string::string(const string &newStr) {
    size = newStr.length();
    str = new char[size];
    for (int i = 0; i <=size; ++i) {
        str[i] = newStr.str[i];
    }
}

void string::operator+(const string &str1) {
    size =  str1.length() + length();
    char *new_str = new char[size];
    int i;
    for (i = 0; i < length(); ++i) {
        new_str[i] = str[i];
    }
    for (int j = 0; j < str1.length(); ++j, ++i) {
        new_str[i] = str1.str[j];
    }

    delete []str;
    str = new_str;
}
