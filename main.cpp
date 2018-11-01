#include <iostream>
#include "btree.h"
#include "string.h"
int main() {
/*
    btree T;
    T.insert(2);
    btree T2(T);

    std::cout << "Hello, World!" << std::endl;
*/
    char *c1 = new char[3];
    c1[0] = 'a';
    c1[1] = 'b';
    string string1(c1);

    char *c = new char[3];
    c[0] = 'a';
    c[1] = 'b';

    string string2(c);
    std::cout << string2.length() << std::endl;
    std::cout << string2.capacity() << std::endl;
    string2+string1;
    std::cout << string2.capacity() << std::endl;



    return 0;
}