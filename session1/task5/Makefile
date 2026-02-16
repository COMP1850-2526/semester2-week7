# Task 5 Makefile

CFLAGS = -g
EXECS = factorial vars

help:
	@echo "Enter 'make' followed by name of an executable"
	@echo "(Options are: $(EXECS))"
	@echo
	@echo "Remove all executables with 'make clean'"

%: %.c
	gcc $(CFLAGS) $< -o $@

clean:
	@rm -f $(EXECS)
	@rm -rf $(patsubst %,%.dSYM,$(EXECS))   # for clang on Macs

.PHONY: clean help
