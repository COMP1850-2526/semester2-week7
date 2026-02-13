# Task 5

This task explores the basic features of the GNU Debugger, GDB.

**Note**: we have provided a makefile to make it easy to compile the programs
for this task. **You do not need to understand how this works!** We will cover
Makefiles in a later session.

## `factorial.c`

This program computes the factorial of the integer provided on the command
line, but it has some problems.

1. Compile the program in the terminal with

       make factorial

   You can see the compiler command echoed in the terminal. Note the use
   of the `-g` option, allowing the program to be debugged.

2. Run the program in the terminal, first without a command line argument,
   then using `5` as the sole argument:

       ./factorial
       ./factorial 5

   The first of these should print a usage message; the second should
   trigger a segmentation fault.

3. Load the program into GDB:

       gdb factorial

   Then start the program with a command line argument of 5:

       start 5

   The program should pause at a temporary breakpoint, just inside `main()`.

4. Print out the values of `argc` and `argv`:

       p argc
       p argv

   The first of these should print 2, the second should print a memory address.

   Then print out the values of two strings held in `argv`:

       p argv[0]
       p argv[1]

5. Use `next` or `n` twice, to move parse the code that parses the command
   line. Print the variable `value`, to check that it is equal to 5 as
   expected.

   You are now on the statement that calls `factorial()`, although this hasn't
   executed yet. Use `step` or `s` to call the function and step inside it.

   GDB will print a message to tell you that the call happened. This message
   will include details of the arguments passed to the function:

       factorial (n=5) at factorial.c:6

6. Use `s` three more times to continue invoking `factorial()` recursively.
   Notice how the value of parameter `n` descreases by 1 each time.

   Then enter `backtrace` or `bt` to view the call stack. This will show
   clearly the details of the recursion.

7. Recurse further by using `s` three more times. At this point `n` should
   have a negative value. It should now be clear that there is nothing
   to stop recursion from continuing until all available stack space has
   been exhausted.

8. Note that we could have learned about the issue without needing to run
   the debugger. To see how, edit `Makefile` and change the value of variable
   `CFLAGS` to be this:

       CFLAGS = -g -Wall -Wextra -Werror

   Remove the old executable with `make clean`, then attempt to rebuild the
   executable with `make factorial`. You should now see an error message
   informing you of the infinite recursion in `factorial()`.

9. Add a base case to the `factorial()` function that prevents the infinite
   recursion from happening. Verify that this has fixed the issue.

   Is all well with `factorial.c` now? Investigate its behaviour further by
   running it with different integer arguments. You should be able to
   identify (and fix) another bug...

   (Hint: what is the limitation that arises from the use of a `long int`
   variable?)
