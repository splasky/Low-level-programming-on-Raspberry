# 'make depend' use makedepend to automatically generate dependencies
ARCH :=arm

ifeq ($(ARCH),arm)
CC :=arm-unknown-linux-gnueabi-gcc
else
CC :=gcc
endif
# define any directories containing header files
INCLUDES = -Isrc/ #-I/home/newhall/include -I../include 

# define library paths in addition to /usr/lib
LFLAGS = # -L/home/newhall/lib -L../lib 

# define any libraries to link into executable
LIBS = build/-lRPI # -lmylib -lm 

# define test source
TEST_SRC = $(wildcard tests/*_tests.c)
TEST = $(patsubst %.c,%,$(TEST_SRC)) 

TARGET = build/libRPI.a

SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)

dev: CFLAGS = $(FLAGS) 
dev: all

$(TARGET): CFLAGS += -fPIC
$(TARGET): build $(OBJS)
	ar rcs $@ $(OBJS)
	ranlib $@

all: $(TARGET) tests 
	@ echo simple compiler named ADXL345 has been compiled

build:
	@mkdir -p build
	@mkdir -p bin

.PHONY: clean depend tests

tests:LDLIBS= -L./build -lRPI
tests:$(TEST)
	sh ./tests/runtests.sh
valgrind:
	VALGRIND="valgrind --log-file=/tmp/valgrind-%p.log" $(MAKE)
	
#$(MAIN): $(OBJS)
#	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

#.c.o:
#	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf build $(OBJS) $(TESTS)
	rm -f tests/tests.log
depend:
	makedepend $(INCLUDES) $^

