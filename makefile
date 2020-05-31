# msort makefile
# author: lcavalini <lucas.cavalini.barboza@gmail.com>
# license: GPLv3

SRC_PATH := src/
BIN_PATH := bin/
TMP_PATH := tmp/

ALL_OBJECTS := $(TMP_PATH)main.o $(TMP_PATH)msort.o

CC=GCC

all: $(BIN_PATH)msort

$(BIN_PATH)msort: $(ALL_OBJECTS)
	cc -o $(BIN_PATH)msort $(ALL_OBJECTS)

$(TMP_PATH)msort.o: $(SRC_PATH)msort.c $(SRC_PATH)msort.h
	cc -o $(TMP_PATH)msort.o -c $(SRC_PATH)msort.c

$(TMP_PATH)main.o: $(SRC_PATH)main.c $(SRC_PATH)msort.h
	cc -o $(TMP_PATH)main.o -c $(SRC_PATH)main.c

clean:
	rm $(ALL_OBJECTS)

