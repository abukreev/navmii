#include <unordered_map>
#include <string>

/*

 (C) Copyright 2012 Navmii Holdings plc.

 Copying, distribution, or reproduction of this document or its part in any printed or electronic form is prohibited 
 without an explicit written permission from Navmii Holdings plc., UK.

 C++ Programming Test B-1 v1.7

 Level: Mid/Senior C++ Developer.
 
 Skills: C++ basics, structured programming, multithreading, low-level programming.

 This file contains a class that a candidate should implement so that we can test their programming skills.

 The class is a Copy-on-Write dynamic string consisting of US-ASCII characters,
 i.e. the usual ASCII characters with codes not exceeding 127. This limitation is introduced to exclude problems related 
 to encodings and localization.

 The Copy-on-Write (CoW) technique is described, for example, in Wikipedia: http://en.wikipedia.org/wiki/Copy-on-write,
 as well as in a number of books and articles.

 The implementation must not use the STL or Boost libraries, or any other third-party libraries,
 or the C library memory or string functions such as memcpy, strcpy, strstr or strlen. This limitation means 
 that you should write even the simplest code, for example, that copies a sequence of characters, by yourself.

 The code should conform to the C++ 2003 standard (ISO/IEC 14882:2003) as much as possible.
 This particularly means you cannot use the new C++ 11 features and the standard library features such as std::atomic.

 The string class must allow copying its instances between threads, but is not required to be thread safe by itself.
 Making a string copy and using it in another thread must be completely safe, while accessing the same string object 
 from different threads is not required to be safe.
 
 Multithreading support in a CoW string means that the string implementation requires the use of platform-specific 
 synchronization or atomicity functions or intrinsics. You are only required to implement the class for a single platform, 
 the one of your preference, for example, one of Windows x86, Linux x86, Mac OS X, iOS, or another popular platform. 
 For the purpose of implementing thread safety, you are allowed to use platform-dependent functions, intrinsics or assembly.

 You can extend or change the interface of the class if you need to without disrupting its functionality or contract. 
 Some service code such as the assignment operator may be omitted in this interface declaration, nevertheless the class
 must be completely functioning in any possible use including copying.

 The implemented methods can be written in a CPP file with the same name or in this header file itself.

 You are also required to implement a unit test for the class in a unit testing framework of your choice,
 for example, Boost Test, Google Test, CppUnit etc.

 As this is a synthetic example not intended for production, the actual performance is not important, 
 especially given the bad reputation of the Copy-on-Write technique in this aspect, 
 although if you manage to provide relatively efficient implementation, it would be beneficial.
 In the first place we prefer simple, clean, easy-to-read, and, of course, correct code.

*/

#include "Navmii.ProgrammingTest.SimpleAsciiStringHash.h"

#ifndef NAVMII_PROGRAMMING_TEST_COW_ASCII_STRING_H
#define NAVMII_PROGRAMMING_TEST_COW_ASCII_STRING_H

namespace Navmii { namespace ProgrammingTest
{
    /**
     * @brief A dynamic Copy-on-Write string with US-ASCII (up to character code 127) characters.
     */
    class CowAsciiString
    {
    public:

        /**
         * @name Construction and Copying
         */
        /**@{*/

        /**
         * @brief Creates an empty string.
         */
        CowAsciiString();

        /**@}*/

        /**
         * @name Length
         */
        /**@{*/

        /**
         * @brief Returns a string length.
         */
        int GetLength() const;

        /**@}*/

        /**
         * @name Characters
         */
        /**@{*/

        /**
         * @brief Sets a character at a specified index (starting from zero).
         *
         * @note The function does not validate the index, if the index is out
         * of the bounds (0, GetLength() - 1), behavior is undefined.
         */
        void SetChar(int index, char character);

        /**
         * @brief Returns the value of a character at a specified index (starting from zero).
         *
         * @note The function does not validate the index, if the index is out
         * of the bounds (0, GetLength() - 1), behavior is undefined.
         */
        char GetChar(int index) const;

        /**
         * @brief Returns the value of a character at a specified index (starting from zero).
         *
         * @note The function does not validate the index, if the index is out
         * of the bounds (0, GetLength() - 1), behavior is undefined.
         */
        char operator [] (int index) const;

        /**@}*/

        /**
         * @name Modification
         */
        /**@{*/

        /**
         * @brief Appends a character to a string.
         *
         * @note If the character is the null terminator ('\0'), behavior is undefined.
         */
        void Append(char character);

        /**
         * @brief Appends another string to this string.
         */
        void Append(const CowAsciiString& other);

        /**
         * @brief Appends another string to this string.
         */
        CowAsciiString& operator += (const CowAsciiString& other);

        /**
         * @brief Splices two strings returning the result.
         *
         * @example <code>CowAsciiString splicedString = CowAsciiString("a") + CowAsciiString("b")</code>;
         * Result: the value of the splicedString is "ab".
         */
        CowAsciiString operator + (const CowAsciiString& other) const;

        /**
         * @brief Inserts a string into a specified position (starting from zero).
         *
         * @example
         * <code>
         * CowAsciiString a = "1245";
         * a.Insert("3", 2);
         * </code>
         * Result: the value of a is "12345";
         *
         * @note The function does not validate the index, if the index is out
         * of the bounds (0, GetLength() - 1), behavior is undefined.
         */
        void Insert(const CowAsciiString& other, int index);

        /**
         * @brief Removes a range of characters from the string.
         *
         * @param startingIndex The index of the first character to remove.
         *
         * @param removedCharactersCount The number of characters to remove.
         * The zero value is acceptable, in this case the function should simply do nothing.
         * If the value is negative, behavior is undefined.
         *
         * @note The function does not validate the indices. If the range
         * to be removed is out of the bounds (0, GetLength() - 1),
         * behavior is undefined.
         */
        void Remove(int startingIndex, int removedCharactersCount);

        /**@}*/

        /**
         * @name Comparison
         */
        /**@{*/

        /**
         * @brief Returns true if strings are equal.
         *
         * @note This method should only implement simple bitwise comparison (i.e. byte-to-byte equality),
         * no complex comparisons are required.
         */
        bool Equals(const CowAsciiString& other) const;

        /**
         * @brief Returns true if strings are equal.
         */
        bool operator == (const CowAsciiString& other) const;

        /**
         * @brief Returns true if strings are not equal.
         */
        bool operator != (const CowAsciiString& other) const;

        /**@}*/

        /**
         * @name Search
         */
        /**@{*/

        /**
         * @brief Searches for the first matching character in a string.
         *
         * @param character The character to search for.
         *
         * @param[out] foundIndex The index of the found character.
         * If the character is not found, the index value is undefined.
         *
         * @return True if the character was found, false otherwise.
         */
        bool Find(char character, /*out*/int& foundIndex) const;

        /**
         * @brief Searches for the first matching substring in a string.
         *
         * @param substring The substring to search for.
         *
         * @param[out] foundIndex The index of the first character of the found substring.
         * If the substring is not found, the index value is undefined.
         *
         * @return True if the substring was found, false otherwise.
         */
        bool Find(const CowAsciiString& substring, /*out*/int& foundIndex) const;

        /**@}*/

        /**
         * @name Null-Terminated Strings
         */
        /**@{*/

        /**
         * @brief Constructs a string from a plain null-terminated C-style string.
         */
        CowAsciiString(const char* source);

        /**
         * @brief Assigns a plain null-terminated C-style string.
         */
        void Assign(const char* source);

        /**
         * @brief Assigns a plain null-terminated C-style string.
         */
        CowAsciiString& operator = (const char* source);

       /**
         * @brief Copies a string into a given plain null-terminated C-style string buffer.
         *
         * @param[out] outputBuffer The buffer to write the string into.
         * When the string is written into the buffer, it is always correctly terminated with the null character ('\0').
         *
         * @param maxOutputBufferSize The maximal size of the output buffer (including the null terminator). 
         * That is, if your buffer is <code>char buffer[32]</code>,
         * the function call <code>ToPlainString(buffer, 32)</code> will assume
         * that the maximal allowed number of characters to be copied is 31.
         */
        void ToPlainString(/*out*/char* outputBuffer, int maxOutputBufferSize) const;

        /**@}*/

    private:
        typedef std::unordered_map<SimpleAsciiString, int, SimpleAsciiStringHash<SimpleAsciiString> > StringsT;
        StringsT m_strings;
    };
}}

#endif // NAVMII_PROGRAMMING_TEST_COW_ASCII_STRING_H

