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

TARGET = build/libRPI.a

SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)

dev: CFLAGS = $(FLAGS) 
dev: all

$(TARGET): CFLAGS += -fPIC
$(TARGET): build $(OBJS)
	ar rcs $@ $(OBJS)
	ranlib $@

all: $(TARGET) 
	@ echo compile finish

build:
	@mkdir -p build
	@mkdir -p bin

.PHONY: clean depend test up help

test:
	$(CC) $(FLAGS) -ggdb $(INCLUDES) ./test/MainADXL345.c $(OBJS) -o ./bin/test_ADXL345
	$(CC) $(FLAGS) -ggdb $(INCLUDES) ./test/blink.c $(OBJS) -o ./bin/test_blink
	$(CC) $(FLAGS) -ggdb $(INCLUDES) ./test/grating.c $(OBJS) -o ./bin/test_grating
	@echo "make test file complete"

# upload execte file to raspberry
up:
	scp -r ../rpi Rpi3:~/workspace 
#$(MAIN): $(OBJS)
#	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

#.c.o:
#	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf build $(OBJS) $(TESTS)
	rm -f bin/*
depend:
	makedepend $(INCLUDES) $^

help:
	@echo "all   : compile to object file"
	@echo "test  : generate test file"
	@echo "clean : clean project"
	@echo "up    : upload file to raspberrypi 3"
