# Task 2: More GDB Commands

The program in `stats.c` computes summary statistics for up to 10,000 numbers
stored in a text file. In this task, you will learn some more GDB commands
that will help you understand its behaviour, then you will make improvements
to the code.

## Observing Program Behaviour

1. Compile the program by entering `make` in the terminal.

2. Run the program without any command line arguments, then run it with
   `data/test1.txt` as the only command line argument. You should see
   values displayed for mean and standard deviation.

   Examine the numbers in `data/test1.txt` and verify by manual calculation
   that the mean value is computed correctly.

3. Collect more information about program behaviour by running it on the
   files `test2.txt`, `test3.txt`, `test4.txt` and `text5.txt`. In each case,
   precede the filename with `data/`.

   Finally, try specifying the name of a file that does not exist. What does
   the program do here?

## Function Breakpoints

1. Load the program into GDB, then establish breakpoints just inside the
   `read_data()` and `mean_value()` functions.

   Note that you don't need to specify line numbers to do this! You can just
   provide function names after the `break` command:

       b read_data
       b mean_value

   Inspect these newly-created breakpoints with

       info b

2. Run the program on a data file, with

       run data/text1.txt

   Execution should pause just inside `read_data()`.

3. Use `c` to resume execution. This should take you to the next function
   breakpoint, inside `mean_value()`.

   Use `c` again to resume execution. The program should run to completion,
   without further interruptions.
