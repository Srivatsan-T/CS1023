.PHONE	: all clean

CC=g++
CFLAGS=-std=c++2a -Wall -Werror -pedantic-errors
FMTDIR=${HOME}/packages/fmt-7.1.3
INCLUDEDIR=${FMTDIR}/include 
LIBDIR=$(FMTDIR)
EXE=thread_pool

SRCS=main.cpp

all	: $(EXE)

$(EXE)	: $(SRCS)
	$(CC) $(CFLAGS) -o $(EXE) -I . $(SRCS) -lpthread

clean	:
	rm -f *.o $(EXE)
