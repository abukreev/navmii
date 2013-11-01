#include <iostream>

#include "Navmii.ProgrammingTest.SimpleAsciiString.h"

using namespace Navmii::ProgrammingTest;

int main () {

    SimpleAsciiString str1("Hello, world!");
    std::cout << "str1: " << str1 << std::endl;
    SimpleAsciiString str2(str1);
    std::cout << "str2: " << str2 << std::endl;
    SimpleAsciiString str3 = str1 + ", and again " + str2;
    std::cout << "str3: " << str3 << std::endl;
    std::cout << "str1 == str2: " << (str1 != str2) << std::endl;
    int pos;
    str1.Find(" ", pos);
    str1.Insert(str2, pos);
    std::cout << "str1: " << str1 << std::endl;

    return 0;
}
