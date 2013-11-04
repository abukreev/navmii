#include <cstddef>
#include <ostream>
#include <string.h>

#include <mymemcpy.h>

#include "Navmii.ProgrammingTest.SimpleAsciiString.h"

using namespace Navmii;
using namespace ProgrammingTest;

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

SimpleAsciiString::SimpleAsciiString() : m_buf(NULL), m_length(0) {
}

SimpleAsciiString::SimpleAsciiString(const char* source) {

    m_buf = NULL;
    m_length = 0;
    Assign(source);
}

SimpleAsciiString::SimpleAsciiString(const char* source, int lengh) {

    if (NULL != source && 0 < lengh) {
        m_length = lengh;
        m_buf = new char[m_length];
        mymemcpy(m_buf, source, m_length);
    } else {
        m_buf = NULL;
        m_length = 0;
    }
}

SimpleAsciiString::SimpleAsciiString(const Navmii::ProgrammingTest::SimpleAsciiString& other) {

    m_buf = NULL;
    m_length = 0;
    Assign(other);
}

SimpleAsciiString::~SimpleAsciiString() {

    if (NULL != m_buf) {
        delete m_buf;
    }
}

char SimpleAsciiString::operator [] (int index) const {

    if (NULL != m_buf && 0 <= index && index < m_length) {
        return m_buf[index];
    } else {
        return '\0';
    }
}
SimpleAsciiString& SimpleAsciiString::operator += (const SimpleAsciiString& other) {

    Append(other);
    return *this;
}

SimpleAsciiString SimpleAsciiString::operator + (const SimpleAsciiString& other) const {

    int lengh = m_length + other.m_length;
    char* buf = new char[lengh];
    if (0 < m_length) {
        mymemcpy(buf, m_buf, m_length);
    }
    if (0 < other.m_length) {
        mymemcpy(buf + m_length, other.m_buf, other.m_length);
    }

    SimpleAsciiString str;
    str.m_buf = buf;
    str.m_length = lengh;

    return str;
}

bool SimpleAsciiString::operator == (const SimpleAsciiString& other) const {

    return Equals(other);
}

bool SimpleAsciiString::operator != (const SimpleAsciiString& other) const {

    return !(*this == other);
}

SimpleAsciiString& SimpleAsciiString::operator = (const char* source) {

    Assign(source);
    return *this;
}

int SimpleAsciiString::GetLength() const {

    return m_length;
}

void SimpleAsciiString::SetChar(int index, char character) {

    if (NULL != m_buf && 0 < index && index < m_length) {
        m_buf[index] = character;
    }
}

char SimpleAsciiString::GetChar(int index) const {

    if (NULL != m_buf && 0 < index && index < m_length) {
        return m_buf[index];
    }
    return '\0';
}

void SimpleAsciiString::Append(char character) {

    Append(SimpleAsciiString(&character, 1));
}

void SimpleAsciiString::Append(const SimpleAsciiString& other) {

    if (other.GetLength() != 0) {
        int lengh = m_length + other.m_length;
        char* buf = new char[lengh];
        if (0 < m_length) {
            mymemcpy(buf, m_buf, m_length);
        }
        if (0 < other.m_length) {
            mymemcpy(buf + m_length, other.m_buf, other.m_length);
        }
        if (NULL != m_buf) {
            delete m_buf;
        }
        m_length = lengh;
        m_buf = buf;
    }
}

void SimpleAsciiString::Insert(const SimpleAsciiString& other, int index) {

    if (other.GetLength() != 0 && 0 <= index && (index < MAX(m_length, 1))) {
        int lengh = m_length + other.m_length;
        char* buf = new char[lengh];
        if (0 < index) {
            mymemcpy(buf, m_buf, index);
        }
        mymemcpy(buf + index, other.m_buf, other.m_length);
        if (index < m_length) {
            mymemcpy(buf + index + other.m_length, m_buf + index, m_length - index);
        }
        if (NULL != m_buf) {
            delete m_buf;
        }
        m_length = lengh;
        m_buf = buf;
    }

}

void SimpleAsciiString::Remove(int startingIndex, int removedCharactersCount) {

    if (0 <= startingIndex && startingIndex < m_length && 0 < removedCharactersCount) {
        memmove(m_buf + startingIndex, m_buf + startingIndex + removedCharactersCount, removedCharactersCount);
        m_length -= removedCharactersCount;
    }
}

bool SimpleAsciiString::Equals(const SimpleAsciiString& other) const {

    return (m_length == other.m_length && (memcmp(m_buf, other.m_buf, m_length) == 0));
}

bool SimpleAsciiString::Find(char character, /*out*/int& foundIndex) const {

    for (int i = 0; i < m_length; ++i) {
        if (m_buf[i] == character) {
            foundIndex = i;
            return true;
        }
    }

    return false;
}

bool SimpleAsciiString::Find(const SimpleAsciiString& substring, /*out*/int& foundIndex) const {

    if (NULL != m_buf) {
        char* p = strstr(m_buf, substring.m_buf);
        if (NULL != p) {
            foundIndex = p - m_buf;
            return true;
        }
    }
    return false;
}

void SimpleAsciiString::Assign(const char* source) {

    if (NULL != source) {
        int length = strlen(source);
        Assign(source, length);
    }
}

void SimpleAsciiString::Assign(const char* source, int length) {

    if (NULL != source) {
        if (NULL != m_buf) {
            delete[] m_buf;
            m_length = 0;
        }
        if (length > 0) {
            m_length = length;
            m_buf = new char[m_length];
            mymemcpy(m_buf, source, m_length);
        }
    }
}

void SimpleAsciiString::Assign(const SimpleAsciiString& other) {

    Assign(other.m_buf, other.m_length);
}

void SimpleAsciiString::ToPlainString(/*out*/char* outputBuffer, int maxOutputBufferSize) const {

    if (NULL != outputBuffer && 1 < maxOutputBufferSize) {
        int lengh = MIN(m_length, maxOutputBufferSize - 1);
        mymemcpy(outputBuffer, m_buf, lengh);
        outputBuffer[lengh] = '\0';
    }
}

std::ostream& Navmii::ProgrammingTest::operator<< (std::ostream& os, const SimpleAsciiString& str) {
    os << "\"" << str.m_buf << "\"";
    return os;
}

