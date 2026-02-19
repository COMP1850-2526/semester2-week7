# Assembly Language in GDB

For this, you should return to the `fizzbuzz` program in Task 1.

## `disassemble` Command

Compile the program with `make`, then load it into GDB. Disassemble the
code of `main()` with

    disas /m main

Notice how GDB shows you fragments of C code, and underneath each fragment
the corresponding assembly language output by the compiler.

Take a look at how the `for` loop begins, with initialization of `i`:

```asm
movl $0x1, -0x10(%rbp)
```

This instruction moves a 32-bit integer, with a value of 1, into a memory
address 16 bytes (`0x10` = 16) before the address referenced by the `%rbp`
register. This register holds a pointer to the base of the stack frame used
by the currently executing function.

Why 16 bytes here? There are four local variables used by the program, each
of type `int`, therefore requiring 4 bytes of storage. We would have to
move 4 bytes from the base of the stack to find the address of the `fizz`
variable, 8 bytes to find the address of `buzz`, and so on. If you look
earlier in the disassembled code, you'll a value of 0 being written into
these memory addresses.

Now take a look at the three `printf()` calls. Each of them is represented
by 5 assembly language instructions. See if you can figure out exactly what
is going on here.

(You'll need to do some research into how function calls are made and how
registers are used at the assembly language level.)

## `nexti` & `stepi` Commands

Reload `fizzbuzz` into GDB if necessary, then enter `start`. The program
should pause just inside `main()`.

Now try stepping through the program using `nexti` or `ni`, instead of
`next` or `n`.

This steps through the program *one CPU instruction at a time*. You won't
see any difference from using `n` until you reach the `for` loop. Here
you should see it takes several uses of `ni` to get past the initial loop
logic and on to the `if` statement.

Use the `advance` command to move ahead to the first call to `printf()`.
If you start using `si` at this point, you'll leave the `fizzbuzz` program
and find that you are stepping through library code!
