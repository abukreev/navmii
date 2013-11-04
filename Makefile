CXX=g++
CXXFLAGS=-c -g -Wall
LDFLAGS=-L./mystdlib -lmystdlib
INCLUDES= -I./mystdlib/include
SOURCES=main.cpp Navmii.ProgrammingTest.SimpleAsciiString.cpp
OBJECTS=$(SOURCES:.cpp=.o)
TARGET=test

all: $(SOURCES) $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $@

.cpp.o: $(SOURCES)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $< -o $@

clean:
	rm -f $(OBJECTS)
