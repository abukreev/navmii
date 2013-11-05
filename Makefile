CXX=g++
CXXFLAGS=-c -g -Wall -std=c++0x
LDFLAGS=-L./mystdlib -lmystdlib
INCLUDES=-I. -I./mystdlib/include
SOURCES=main.cpp Navmii.ProgrammingTest.SimpleAsciiString.cpp Navmii.ProgrammingTest.CowAsciiString.cpp
OBJECTS=$(SOURCES:.cpp=.o)
LIB=./mystdlib/libmystdlib.a
TARGET=test

all: $(SOURCES) $(TARGET)

$(TARGET): $(OBJECTS) $(LIB)
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $@

$(LIB):
	cd mystdlib; make

.cpp.o: $(SOURCES)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $< -o $@

clean:
	rm -f $(OBJECTS)
	cd mystdlib; make clean
