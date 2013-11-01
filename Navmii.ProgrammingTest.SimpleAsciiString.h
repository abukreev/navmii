#ifndef NAVMII_PROGRAMMING_TEST_COW_ASCII_STRING_H
#define NAVMII_PROGRAMMING_TEST_COW_ASCII_STRING_H

#include <iostream>

namespace Navmii { namespace ProgrammingTest
{
    /**
     * @brief A dynamic Copy-on-Write string with US-ASCII (up to character code 127) characters.
     */
    class SimpleAsciiString
    {
    public:

        /**
         * @name Construction and Copying
         */
        /**@{*/

        /**
         * @brief Creates an empty string.
         */
        SimpleAsciiString();

        /**
         * @name Construction and Copying
         */
        /**@{*/

        /**
         * @brief Creates a copy of string other.
         */
        SimpleAsciiString(const SimpleAsciiString& other);
        /**@}*/

        /**@}*/

        /**
         * @name Null-Terminated Strings
         */
        /**@{*/

        /**
         * @brief Constructs a string from a plain null-terminated C-style string.
         */
        SimpleAsciiString(const char* source);

        /**@}*/

        /**
         * @name Null-Terminated Strings
         */
        /**@{*/

        /**
         * @brief Constructs a string from an array of size characters.
         */
        SimpleAsciiString(const char* source, int size);

        /**@}*/

        /**
         * @name Destructor
         */
        /**@{*/

        ~SimpleAsciiString();

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
        void Append(const SimpleAsciiString& other);

        /**
         * @brief Appends another string to this string.
         */
        SimpleAsciiString& operator += (const SimpleAsciiString& other);

        /**
         * @brief Splices two strings returning the result.
         *
         * @example <code>SimpleAsciiString splicedString = SimpleAsciiString("a") + SimpleAsciiString("b")</code>;
         * Result: the value of the splicedString is "ab".
         */
        SimpleAsciiString operator + (const SimpleAsciiString& other) const;

        /**
         * @brief Inserts a string into a specified position (starting from zero).
         *
         * @example
         * <code>
         * SimpleAsciiString a = "1245";
         * a.Insert("3", 2);
         * </code>
         * Result: the value of a is "12345";
         *
         * @note The function does not validate the index, if the index is out
         * of the bounds (0, GetLength() - 1), behavior is undefined.
         */
        void Insert(const SimpleAsciiString& other, int index);

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
        bool Equals(const SimpleAsciiString& other) const;

        /**
         * @brief Returns true if strings are equal.
         */
        bool operator == (const SimpleAsciiString& other) const;

        /**
         * @brief Returns true if strings are not equal.
         */
        bool operator != (const SimpleAsciiString& other) const;

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
        bool Find(const SimpleAsciiString& substring, /*out*/int& foundIndex) const;

        /**
         * @brief Assigns a plain null-terminated C-style string.
         */
        void Assign(const char* source);

        void Assign(const char* source, int length);

        /**
         * @brief Assigns an other string.
         */
        void Assign(const SimpleAsciiString& other);

        /**
         * @brief Assigns a plain null-terminated C-style string.
         */
        SimpleAsciiString& operator = (const char* source);

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

        friend std::ostream& Navmii::ProgrammingTest::operator<< (std::ostream& os, const SimpleAsciiString& str);

    private:
        char* m_buf;
        int m_length;

    };
    std::ostream& operator<< (std::ostream& os, const SimpleAsciiString& str);
}}

#endif // NAVMII_PROGRAMMING_TEST_COW_ASCII_STRING_H

