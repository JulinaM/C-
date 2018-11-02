//
// Created by jmaharja on 11/1/18.
//

#include <iostream>

class string{
private:
    char* str;
    int size;

public:
    string();
    string(int capacity);
    string(const string& newStr);
    string(char* chars);
    ~string();
    int length() const;
    int capacity() const;
    void operator +(const string& str1);
    void operator = (const string& str1);
    void swap(string& str1, string& str2);
};

string::string()
{
    str = new char[129];
    size = 128;
    for (int i = 0; i <= size; ++i) {
        str[i] = '\0';
    }
}

string::string(int capacity) {
    str = new char[capacity+1];
    size = capacity;
    for (int i = 0; i <= size; ++i) {
        str[i] = '\0';
    }
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

string::string(const string &newStr) {
    size = newStr.length();
    str = new char[size];
    for (int i = 0; i <=size; ++i) {
        str[i] = newStr.str[i];
    }
}

string::~string() {
    delete []str;
    size = 0;
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

void string::operator=(const string &str1) {
    if(str != nullptr) delete []str;

    size = str1.size;
    str = new char[size];
    for (int i = 0; i < size; ++i) {
        str[i] = str1.str[i];
    }
}

void string::swap(string& str1, string& str2){
    char *temp_str = str1.str;
    int temp_size = str1.size;

    str1 = str2.str;
    size = str2.size;

    str2 = temp_str;
    str2.size = temp_size;
}
