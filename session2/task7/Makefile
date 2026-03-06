# Makefile for Task 7

CFLAGS = -g -Wall -Wextra -Werror

pgm_tools: pgm_tools.c
	gcc $(CFLAGS) pgm_tools.c -o pgm_tools

clean:
	@rm -f pgm_tools
	@rm -rf pgm_tools.dSYM   # for clang on Macs

.PHONY: clean
