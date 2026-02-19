# Week 7: Debugging

Tasks for Week 7, mainly focused on debugging of C programs.

Keep in mind that to debug C programs, you need to include the `-g` option
when compiling source code files, i.e.

    gcc -g prog.c -o prog

If you ever see the message "no debugging symbols found" when loading an
executable into GDB, this means you forgot the `-g` option!

Note: many of the tasks manage compilation using the [`make`][mk] utility,
and in most of these we have already specified the `-g` option for you.

> [!CAUTION]
> Take care to remove any executables before you commit and push changes
> back to GitHub. For those tasks managed by makefiles, you can achieve
> this very easily by entering the command `make clean`.

For Session 2, make sure that you have installed the C/C++ Extension Pack
into the VS Code environment. (VS Code should prompt you to do this
the first time that you open a file of C source code.)


[mk]: https://www.gnu.org/software/make/manual/html_node/index.html
