CXX=g++
CXXFLAGS=-c -g -Wall
LDFLAGS=-L./mystdlib -lmystdlib
INCLUDES= -I./mystdlib/include
SOURCES=main.cpp Navmii.ProgrammingTest.SimpleAsciiString.cpp
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
