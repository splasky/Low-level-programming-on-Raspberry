# 'make depend' use makedepend to automatically generate dependencies
MAIN = MainADXL345
CC = gcc
CFLAGS = -g -Wall -std=c99 -Wextra

# define any directories containing header files
INCLUDES = -Isrc/ #-I/home/newhall/include -I../include 

# define library paths in addition to /usr/lib
LFLAGS = # -L/home/newhall/lib -L../lib 

# define any libraries to link into executable
LIBS = # -lmylib -lm 

SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)

.PHONY: clean depend

all: $(MAIN)
	@ echo simple compiler named ADXL345 has been compiled

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) src/*.o *~ $(MAIN)

depend:
	makedepend $(INCLUDES) $^
