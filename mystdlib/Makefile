INCLUDEDIR=./include
SOURCEDIR=./src
OBJECTDIR=./obj
CC=gcc
CFLAGS=-c -g -Wall -I$(INCLUDEDIR)
AR=ar
ARFLAGS=-r
SOURCEFILES=mymemcpy.c mystrlen.c mymemcmp.c mymemmove.c mystrstr.c
SOURCES=$(patsubst %.c,$(SOURCEDIR)/%.c,$(SOURCEFILES))
OBJECTS=$(patsubst %.c,$(OBJECTDIR)/%.o,$(SOURCEFILES))
TARGET=libmystdlib.a

all: $(TARGET)

$(TARGET): $(OBJECTDIR) $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $ $(OBJECTS)

$(OBJECTDIR)/%.o: $(SOURCEDIR)/%.c
	$(CC) -c $(CFLAGS) -o $@ $< 

$(OBJECTDIR):
	mkdir -p $@

clean:
	rm -f $(OBJECTS)
