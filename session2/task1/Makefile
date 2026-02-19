# Makefile for Task 1

CFLAGS = -g -Wall -Wextra -Werror

fizzbuzz: fizzbuzz.c
	gcc $(CFLAGS) fizzbuzz.c -o fizzbuzz

clean:
	@rm -f fizzbuzz
	@rm -rf fizzbuzz.dSYM   # for clang on Macs

.PHONY: clean
