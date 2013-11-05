#ifndef SIMPLE_ASCII_STRING_HASH_H
#define SIMPLE_ASCII_STRING_HASH_H

#include <Navmii.ProgrammingTest.SimpleAsciiString.h>

namespace Navmii {
    namespace ProgrammingTest {
        template<class T>
        class SimpleAsciiStringHash;
        template <>
        class SimpleAsciiStringHash<SimpleAsciiString> {
        public:
            std::size_t operator() (SimpleAsciiString const& s) const {
                size_t result = 0;
                for (int i = 0; i < s.GetLength(); ++i) {
                    result += i * (int) s[i];
                }
                return result;
            }
        };
    };
};

#endif // SIMPLE_ASCII_STRING_HASH_H
