#include <iostream>

#include "Navmii.ProgrammingTest.CowAsciiString.h"

using namespace Navmii::ProgrammingTest;

int main () {

    CowAsciiString str1("Hello, world!");
    std::cout << "str1: " << str1 << std::endl;
    CowAsciiString str2(str1);
    std::cout << "str2: " << str2 << std::endl;
    CowAsciiString str3 = str1 + ", and again " + str2;
    std::cout << "str3: " << str3 << std::endl;
    std::cout << "str1 == str2: " << (str1 != str2) << std::endl;
    
    int pos;
    str1.Find(" ", pos);
    str1.Insert(str2, pos);
    std::cout << "str1: " << str1 << std::endl;

    return 0;
}
