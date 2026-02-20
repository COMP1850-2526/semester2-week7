# GDB's TUI Mode

> [!NOTE]
> This will work best in a terminal on a Linux machine. It will work a bit
> less well in the terminal of the VS Code environment in a Codespace.
>
> If you do try this in a Codespace, be sure to maximize the size of
> the terminal!

Return to the `fizzbuzz` program in Task 1. Compile the program with `make`,
then load it into GDB.

Enter `start` to pause execution just inside `main()`. Then enter

    tui enable

The display should change to show the source code in the upper panel, with
the current line highlighted. GDB commands are entered in the lower panel.
Enter `n` a couple of times and you should see the highlighting move to
subsequent lines of the program.

Try using the mouse wheel to scroll through the program's source code.

Now enter

    layout split

This splits the upper panel in two. The new panel appearing in the middle
shows the assembly language for the program.

Enter `n` a few more times. You should see the highlighting move by more
than one CPU instruction - demonstrating that each line compiles to more than
one instruction.

Enter `ni` a few times. Now the highlighting in the middle panel moves ahead
by one instruction each time, but it takes several of these commands before
the highlighting moves to the next line of source code in the upper panel.

Now return to the 'source + commands' view with

    layout src

Then use `n` to execute the print statements. Notice how printing to stdout
messes up the display. You can press `Ctrl+L` to refresh the screen and
fix the issue.
