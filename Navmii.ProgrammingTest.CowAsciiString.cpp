#include <Navmii.ProgrammingTest.CowAsciiString.h>

using namespace Navmii::ProgrammingTest;

CowAsciiString::CowAsciiString() {

}
CowAsciiString::CowAsciiString(const char* source) {

    for (StringsT::iterator it = m_strings.begin(), end = m_strings.end(); it != end; ++i) {
        if (it->first == source) {
            
        }
    }
}

char CowAsciiString::operator [] (int index) const {

    return '\0';
}

CowAsciiString& CowAsciiString::operator += (const CowAsciiString& other) {

    return *this;
}

CowAsciiString CowAsciiString::operator + (const CowAsciiString& other) const {

    return CowAsciiString();
}

bool CowAsciiString::operator == (const CowAsciiString& other) const {

    return false;
}

bool CowAsciiString::operator != (const CowAsciiString& other) const {

    return false;
}

CowAsciiString& CowAsciiString::operator = (const char* source) {

    return *this;
}

int CowAsciiString::GetLength() const {

    return 0;
}

void CowAsciiString::SetChar(int index, char character) {
}

char CowAsciiString::GetChar(int index) const {

    return '\0';
}

void CowAsciiString::Append(char character) {
}

void CowAsciiString::Append(const CowAsciiString& other) {
}

void CowAsciiString::Insert(const CowAsciiString& other, int index) {
}

void CowAsciiString::Remove(int startingIndex, int removedCharactersCount) {
}

bool CowAsciiString::Equals(const CowAsciiString& other) const {

    return false;
}

bool CowAsciiString::Find(char character, /*out*/int& foundIndex) const {

    return false;
}

bool CowAsciiString::Find(const CowAsciiString& substring, /*out*/int& foundIndex) const {

    return false;
}

void CowAsciiString::Assign(const char* source) {

}

void CowAsciiString::ToPlainString(/*out*/char* outputBuffer, int maxOutputBufferSize) const {

}

