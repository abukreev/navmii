CC=gcc
AR=ar
ARFLAGS=-r
INCLUDEDIR=include
SOURCEDIR=src
OBJECTDIR=obj
CFLAGS=-c -g -Wall -I$(INCLUDEDIR)
SOURCEFILES=mymemcpy.c
SOURCES=$(SOURCEFILES:%.c=$(SOURCEDIR)/%.c)
OBJECTS=$(SOURCEFILES:%.c=$(OBJECTDIR)/%.o)
TARGET=libmystdlib.a

all: $(TARGET)

$(TARGET): $(OBJECTDIR) $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $ $(OBJECTS)

$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) $< -o $@

$(OBJECTDIR):
	mkdir -p $@

clean:
	rm -f $(OBJECTS)
