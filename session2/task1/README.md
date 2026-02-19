# Task 1: Display & Watch in GDB

The program in `fizzbuzz.c` is an implementation of the classic children's
game [Fizz Buzz](https://en.wikipedia.org/wiki/Fizz_buzz).

Instead of fully simulating the game, the program just counts the numbers of
times that "Fizz", "Buzz" and "Fizz Buzz" should have been said by players,
for numbers in the range 1-100.

We could add print statements to check that these counts are being computed
correctly, but let's use GDB to see what's happening instead.

1. Compile the program in the terminal, by entering `make`. Then run the
   program to see how it behaves.

2. Load the program into GDB. Add a breakpoint on line 11 and then run.

3. Use the `info` command to view details of the program's variables:

       info locals

   Counting variables `fizz`, `buzz` and `fizz_buzz` should all have the
   value 0. You might see that loop variable `i` doesn't have a sensible
   initial value yet. This is because it isn't assigned its initial value
   of 0 until the loop actually starts.

4. Let's ask GDB to tell us the values of `i`, `fizz` and `buzz` each time
   that the program pauses execution. We do this using the `display` command:

       display i
       display fizz
       display buzz

5. Use `next` or `n` a few times to move through the program. Notice how
   the current values of the three variables are displayed, and that
   the displays are labelled 1, 2 and 3.

6. Keep using `n`, observing the changes to `i` as the `for` loop progresses.
   Keep doing this until `i` reaches 16. This should be enough to confirm
   that `fizz` is being incremented when `i` is divisible by 3 and not by 5,
   and `buzz` is being incremented when `i` is divisible by 5 and not by 3,
   as required in the game.

7. Enter `c` to resume normal execution. Notice that now we no longer see
   the values of the three variables. We only see their values when we
   have paused the program.

8. Rerun the program. It should stop on line 11. The three variables will be
   displayed again. Cancel the display of `fizz` and `buzz` with these
   commands:

       undisplay 2
       undisplay 3

   **Note the use of the numeric labels here, not the variable names!**

   Note also that you can enter `undisplay` without a label, and it will
   cancel all display requests.

9. Set a **watchpoint** for variable `fizz_buzz`, like so:

       watch fizz_buzz

   Now resume execution with `c`. The program should continue until the
   point where `fizz_buzz` is first incremented. You should see its old and
   new values. You should also see the current value of `i`, since you
   didn't cancel its display.

   Continue entering `c` a few more times, until you can confirm that
   `fizz_buzz` is being incremented only when `i` is divisible by both 3
   and 5. Then enter `q` to quit the debugger.
