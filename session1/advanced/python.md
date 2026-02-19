# Debugging Python

Pdb can be used in other ways. It's also possible to debug Python code
from within the VS Code interface.

1. Go back to a Python program that you wrote in Semester 1. Add this to
   a point in your code where you want to start debugging:

   ```python
   breakpoint()
   ```

   Run the program and see what happens.

2. Investigate these Pdb commands:

       source
       jump
       display
       whatis

   In each case, read up on the command using the [Pdb documentation][pdb],
   then try out the command with a real Python program.

3. Read the [VS Code documentation on debugging in Python][vsv], then repeat
   Task 4 using VS Code instead of the command line interface of Pdb.


[pdb]: https://docs.python.org/3/library/pdb.html
[vsc]: https://code.visualstudio.com/docs/python/debugging
