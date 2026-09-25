CC ?= cc
CFLAGS ?= -std=c11 -Wall -Wextra -Werror -O0 -g

.PHONY: all clean

all: tinyheap

tinyheap: tinyheap.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f tinyheap
