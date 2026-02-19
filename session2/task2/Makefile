# Makefile for Task 2

CFLAGS = -g -Wall -Wextra -Werror

stats: stats.c
	gcc $(CFLAGS) stats.c -o stats -lm

clean:
	@rm -f stats
	@rm -rf stats.dSYM   # for clang on Macs

.PHONY: clean
