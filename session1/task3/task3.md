# Task 3

1. Examine `task3.c`. This is a program to sum the values of integers
   specified on the command line. The function `get_values()` processes the
   command line arguments, returning a pointer to dynamically-allocated
   storage containing the specified values. The function `sum_values()` sums
   these values, returning the result as a long integer.

   Notice how this code uses assertions and the conditional compilation
   feature discussed on the slides.

2. Examine `Makefile`. This is a **makefile** to handle compilation of
   `task3.c`. You do not need to understand exactly how this works just yet,
   as we will cover this properly in a later session.

   Notice how the makefile defines a variable named `CFLAGS`, containing
   options for the compiler. You'll be modifying this later.

   Using this makefile, you can compile the program from the terminal by
   entering `make task3` or simply `make` on its own. You can remove
   the executable by entering `make clean`.

## Assertions

1. In a terminal window, compile the program by entering

       make

   Then run the program, supplying some suitable input on the command line:

       ./task3 1 2 3 4 5 6

   You should see that it sums the values correctly.

2. Try running the program with no command line arguments:

       ./task3

   The program halts due to a failed assertion. Study the output from the
   program carefully. Notice that it gives you details of the assertion that
   failed and where it occurs in the source code.

   In this case, the assertion `data != NULL` failed; in other words, `data`
   must have the value `NULL`. This happened on line 23, just inside the
   `sum_values()` function.

3. Now comment out line 41, so that `num_values` is not given the correct
   value. Recompile by entering `make`, then run the program with a few
   integers as command line arguments. This time, the other assertion in
   `sum_values()` should fail.

   **Uncomment line 41 before proceeding further!**

4. Check the size of the executable by entering this command in the terminal
   window:

       wc -c task3

   Make a note of the number you see. Then edit `Makefile` so that the
   `CFLAGS` variable includes a definition of the `NDEBUG` preprocessor
   symbol:

       CFLAGS = -DNDEBUG -Wall -Wextra -Werror

   Recompile the application and check its size again. You should see that it
   is slightly smaller, because the assertion code has been removed.

5. Run the program, without command line arguments. You should no longer
   see a failed assertion.

6. Comment out line 41 again, then recompile the program, and run it with
   some numbers as command line arguments. You won't see a failed assertion
   here, either (and the result of the calculation will be wrong!)

   Once again, uncomment line 41 before proceeding further.

## Conditional Debugging Statements

1. You will have noticed in the previous experiments that some of the calls
   made to `printf()` in `task3.c` are not executed. This is because they
   have not yet been compiled into the executable, `task3`.

   To enable them, edit `Makefile` and change the definition of `CFLAGS` to

       CFLAGS = -DVERBOSE -Wall -Wextra -Werror

   This will ensure that the `VERBOSE` preprocessor symbol is defined when
   the program is next compiled.

2. Enter `make clean` to remove the previous version of the executable,
   followed by `make` to recreate it.

3. Run the application in the same ways that you did previously. You should
   see that the previously-missing print statements are now executed.

