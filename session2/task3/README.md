# Task 3: The Mysterious Login Problem

The program `testlogin.c` simulates a password-based login system, but it
has a big problem. In this task, you will use GDB to help you understand the
nature of this problem.

## Discovery

1. Compile the program by entering `make` in the terminal window.

2. Run the program with

       ./testlogin

   Enter the word "penguin" (all lowercase) when prompted for a password.
   The program should inform you that login succeeded.

   **Note that you will not see any of the typed characters appear in the
   terminal!** - as is normally the case for password-based authentication.
   If you find this hard to use, you can create a more accessible version of
   the program with `make visible`.

3. Run the program again, but this time enter `aaaaaaa` as the password.
   You should see a 'Login failed' message.

4. Repeat the above several times, with progressively longer strings of `a`
   characters. You will see the 'Login failed' message again, but eventually
   (with a string of around 40 `a` characters), login will succeed!

   This is clearly a serious vulnerability, as it allows an attacker to
   access the system without knowing the real password. But why does
   the problem occur?

## Diagnosis

1. Load the program into GDB, set a breakpoint at line 23, then run.

2. Print the current value of the `password` variable. Use the `n` command
   to execute the call to `strcpy()`, then print the variable again.

   Note: you can just enter `p` on its own to reprint the expression that
   was last printed.

   You should see that `password` now holds the password required to gain
   access to the system: the string "penguin".

3. Clear the breakpoint on line 23, then set a new breakpoint at line 41
   and resume execution. The following sequence of abbreviated commands will
   achieve this:

       cl 23
       b 41
       c

   Before the program reaches the new breakpoint, you will be prompted to
   enter a password. Input the string `aaaaaaa`.

   If you try printing the variable `input` using the `p` command, it should
   have the value "aaaaaaa".

4. Now try examining the contents of program memory, starting at the address
   used by `input`. You can use the `x` command for this:

       x/40xb input

   This will display 40 bytes of memory, each as a hexadecimal value. You
   will see this displayed as 5 rows of 8 bytes, with each row preceded by
   the memory address of the start of the row.

   Notice the repeating value `0x61` - the ASCII code for the `a` character.

5. Try this again, using `c` as the format:

       x/40c input

   This will try to interpret the byte at each memory address as a character.
   If the byte is within the range of ASCII characters, you will see the
   character displayed, preceded by its ASCII character code; otherwise, you
   will see the byte displayed as an 'octal escape sequence' (a standard
   way of representing non-printable characters in programs).

   See the GDB manual for [more on how you can examine memory](https://sourceware.org/gdb/current/onlinedocs/gdb.html/Memory.html).

6. Enter `run` to rerun the program, then enter a string of 20 `a` characters
   when prompted. Redisplay the block of memory with

       x/40 input

   Notice how there is no `c` in this command. GDB remembers the previously
   used output format and doesn't require you to specify it again unless
   you wish to change it.

   If you look at the output, you will see that the sequence of `a` characters
   is extending further into memory, getting closer to the stored password
   ("penguin").

7. Rerun the program again, and enter the string of 40 `a` characters that
   you tried earlier. Use GDB's `x` command to examine memory again. You
   should see that the stored password has been completely overwritten.

   This is a simple example of a **heap-based buffer overrun**.

   Buffer overruns can happen on both the stack and the heap, although these
   days compilers often add code that can detect 'stack smashing' at run time
   and warn you about it.

8. **Optional**: fix the bug, and verify that your fix works.

   This should required a change to only a single line in `testlogin.c`!
