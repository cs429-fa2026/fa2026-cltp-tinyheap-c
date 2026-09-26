CC ?= cc
CFLAGS ?= -std=c11 -Wall -Wextra -Werror -O0 -g

.PHONY: all check clean

all: tinyheap

tinyheap: tinyheap.c
	$(CC) $(CFLAGS) -o $@ $<

check: tinyheap
	@set -e; for input in testcases/*.in; do \
		expected=$${input%.in}.expected; \
		./tinyheap < "$$input" | diff -u "$$expected" -; \
	done

clean:
	rm -f tinyheap
