CXX=g++
CXXFLAGS=-c -g -Wall
LDFLAGS=
INCLUDES= -I./include
SOURCES=main.cpp Navmii.ProgrammingTest.CowAsciiString.cpp
OBJECTS=$(SOURCES:.cpp=.o)
TARGET=test

all: $(SOURCES) $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o: $(SOURCES)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $< -o $@

clean:
	rm -f $(OBJECTS)
