#include <cstddef>
#include <string.h>

#include "Navmii.ProgrammingTest.CowAsciiString.h"

using namespace Navmii;
using namespace ProgrammingTest;

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

CowAsciiString::CowAsciiString() : m_buf(NULL), m_length(0) {
}

CowAsciiString::CowAsciiString(const char* source) {

    m_buf = NULL;
    m_length = 0;
    Assign(source);
}

CowAsciiString::CowAsciiString(const char* source, int lengh) {

    if (NULL != source && 0 < lengh) {
        m_length = lengh;
        m_buf = new char[m_length];
        memcpy(m_buf, source, m_length);
    } else {
        m_buf = NULL;
        m_length = 0;
    }
}

CowAsciiString::CowAsciiString(const Navmii::ProgrammingTest::CowAsciiString& other) {

    m_buf = NULL;
    m_length = 0;
    Assign(other);
}

CowAsciiString::~CowAsciiString() {

    if (NULL != m_buf) {
        delete m_buf;
    }
}

char CowAsciiString::operator [] (int index) const {

    if (NULL != m_buf && 0 <= index && index < m_length) {
        return m_buf[index];
    } else {
        return '\0';
    }
}
CowAsciiString& CowAsciiString::operator += (const CowAsciiString& other) {

    Append(other);
    return *this;
}

CowAsciiString CowAsciiString::operator + (const CowAsciiString& other) const {

    int lengh = m_length + other.m_length;
    char* buf = new char[lengh];
    if (0 < m_length) {
        memcpy(buf, m_buf, m_length);
    }
    if (0 < other.m_length) {
        memcpy(buf + m_length, other.m_buf, other.m_length);
    }

    CowAsciiString str;
    str.m_buf = buf;
    str.m_length = lengh;

    return str;
}

bool CowAsciiString::operator == (const CowAsciiString& other) const {

    return Equals(other);
}

bool CowAsciiString::operator != (const CowAsciiString& other) const {

    return !(*this == other);
}

CowAsciiString& CowAsciiString::operator = (const char* source) {

    Assign(source);
    return *this;
}

int CowAsciiString::GetLength() const {

    return m_length;
}

void CowAsciiString::SetChar(int index, char character) {

    if (NULL != m_buf && 0 < index && index < m_length) {
        m_buf[index] = character;
    }
}

char CowAsciiString::GetChar(int index) const {

    if (NULL != m_buf && 0 < index && index < m_length) {
        return m_buf[index];
    }
    return '\0';
}

void CowAsciiString::Append(char character) {

    Append(CowAsciiString(&character, 1));
}

void CowAsciiString::Append(const CowAsciiString& other) {

    if (other.GetLength() != 0) {
        int lengh = m_length + other.m_length;
        char* buf = new char[lengh];
        if (0 < m_length) {
            memcpy(buf, m_buf, m_length);
        }
        if (0 < other.m_length) {
            memcpy(buf + m_length, other.m_buf, other.m_length);
        }
        if (NULL != m_buf) {
            delete m_buf;
        }
        m_length = lengh;
        m_buf = buf;
    }
}

void CowAsciiString::Insert(const CowAsciiString& other, int index) {

    if (other.GetLength() != 0 && 0 <= index && (index < MAX(m_length, 1))) {
        int lengh = m_length + other.m_length;
        char* buf = new char[lengh];
        if (0 < index) {
            memcpy(buf, m_buf, index);
        }
        memcpy(buf + index, other.m_buf, other.m_length);
        if (index < m_length) {
            memcpy(buf + index + other.m_length, m_buf + index, m_length - index);
        }
        if (NULL != m_buf) {
            delete m_buf;
        }
        m_length = lengh;
        m_buf = buf;
    }

}

void CowAsciiString::Remove(int startingIndex, int removedCharactersCount) {

    if (0 <= startingIndex && startingIndex < m_length && 0 < removedCharactersCount) {
        memmove(m_buf + startingIndex, m_buf + startingIndex + removedCharactersCount, removedCharactersCount);
        m_length -= removedCharactersCount;
    }
}

bool CowAsciiString::Equals(const CowAsciiString& other) const {

    return (m_length == other.m_length && (memcmp(m_buf, other.m_buf, m_length) == 0));
}

bool CowAsciiString::Find(char character, /*out*/int& foundIndex) const {

    for (int i = 0; i < m_length; ++i) {
        if (m_buf[i] == character) {
            foundIndex = i;
            return true;
        }
    }

    return false;
}

bool CowAsciiString::Find(const CowAsciiString& substring, /*out*/int& foundIndex) const {

    if (NULL != m_buf) {
        char* p = strstr(m_buf, substring.m_buf);
        if (NULL != p) {
            foundIndex = p - m_buf;
            return true;
        }
    }
    return false;
}

void CowAsciiString::Assign(const char* source) {

    if (NULL != source) {
        int length = strlen(source);
        Assign(source, length);
    }
}

void CowAsciiString::Assign(const char* source, int length) {

    if (NULL != source) {
        if (NULL != m_buf) {
            delete[] m_buf;
            m_length = 0;
        }
        if (length > 0) {
            m_length = length;
            m_buf = new char[m_length];
            memcpy(m_buf, source, m_length);
        }
    }
}

void CowAsciiString::Assign(const CowAsciiString& other) {

    Assign(other.m_buf, other.m_length);
}

void CowAsciiString::ToPlainString(/*out*/char* outputBuffer, int maxOutputBufferSize) const {

    if (NULL != outputBuffer && 1 < maxOutputBufferSize) {
        int lengh = MIN(m_length, maxOutputBufferSize - 1);
        memcpy(outputBuffer, m_buf, lengh);
        outputBuffer[lengh] = '\0';
    }
}

std::ostream& Navmii::ProgrammingTest::operator<< (std::ostream& os, const CowAsciiString& str) {
    os << "\"" << str.m_buf << "\"";
    return os;
}

