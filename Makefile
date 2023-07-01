CC := gcc
#CFLAGS := 
DEST := ./build/

all: strcpy.c
	mkdir -p build
	$(CC) strcpy.c -lcs50 -o $(DEST)/strcpy 