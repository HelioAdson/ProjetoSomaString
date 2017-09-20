IDIR=../include
CC=g++
CFLAGS=-I$(IDIR)

ODIR=obj

_DEPS = string_soma.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = testa_string_soma_stdin.o string_soma.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

SRC = testa_string_soma.cpp string_soma.cpp

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -std=c++11 -c -o $@ $< $(CFLAGS)

testa_string_soma_stdin: $(OBJ)
	g++ -o $@ $^ $(CFLAGS)

porcentagem:
	g++ $(CFLAGS) -std=c++11 -ftest-coverage -fprofile-arcs -g testa_string_soma_stdin.cpp string_soma.cpp -o $@

test: $(SRC)
	g++ $(CFLAGS) -std=c++11 -I /usr/local/include  -pthread $^ /usr/local/lib/libgtest.a -o $@
