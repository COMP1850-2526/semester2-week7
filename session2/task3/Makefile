# Makefile for Task 3

hidden:
	gcc -w -g testlogin.c -o testlogin

visible:
	gcc -DVISIBLE -w -g testlogin.c -o testlogin

clean:
	@rm -f testlogin
	@rm -rf testlogin.dSYM    # for clang on Macs


.PHONY: hidden visible clean
