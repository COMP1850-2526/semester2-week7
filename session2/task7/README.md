# Task 7

In this task, you'll use everything you've learned during the week to
investigate and debug a larger C application. The code for this application
can be found in `pgm_tools.c`.

The application can be used to perform simple image processing operations on
grayscale images. It loads an image from disk, then offers the user a menu of
different processing options. After processing the image in the required
manner, the user is prompted to enter a filename. The processed image is then
saved to disk as a file with that specified name.

## Background Information

**PGM (Portable Gray Map)** is part of a [family of simple file formats][netpbm]
that can be used for the storage of images.

PGM is actually _two_ file formats, one text-based and the other binary. We
consider only the text-based format here.

PGM files are suitable for storing grayscale images - i.e., images in which
each pixel is a single integer, representing a shade of gray. This ranges
from a minimum of 0 (black) up to a specified maximum value (white). The
maximum is usually 255, allowing for 256 distinct shades of gray for each
pixel.

A text-based PGM file consists of:

- The string "P2", which identifies the file as a text-based PGM image
- An optional comment line, starting with a `#` character
- Width and height dimensions
- Maximum gray value
- A grid of pixel values representing the image

Here's the example from Wikipedia's page on the PGM format:

```
P2
# Shows the word "FEEP"
24 7
15
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  3  3  3  3  0  0  7  7  7  7  0  0 11 11 11 11  0  0 15 15 15 15  0
0  3  0  0  0  0  0  7  0  0  0  0  0 11  0  0  0  0  0 15  0  0 15  0
0  3  3  3  0  0  0  7  7  7  0  0  0 11 11 11  0  0  0 15 15 15 15  0
0  3  0  0  0  0  0  7  0  0  0  0  0 11  0  0  0  0  0 15  0  0  0  0
0  3  0  0  0  0  0  7  7  7  7  0  0 11 11 11 11  0  0 15  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0

```

And here's what the resulting image looks like, magnified for clarity:

![](images/feep.png)

## Setting Up Your Environment

In GitHub Codespaces, you may find it helpful to install a PGM viewer extension
to visualise your images:

1. Click on the Extensions icon in the sidebar (or press Ctrl+Shift+X)
2. Search for "PBM Viewer" (this supports PBM, PGM, and PPM formats)
3. Install the extension
4. After installation, you can right-click on any `.pgm` file and select
   "Open with PBM Viewer"

This will allow you to see the actual images instead of just the raw text data.

## Your Task

1. Use the provided makefile to compile the application, then try running
   it on some of the `.pgm` files in the `images` subdirectory. This should
   reveal some problems.

2. Use GDB and the other tools explored this week to investigate the nature
   of these problems, then fix them.

   Note: there are **five** problems that will need to be fixed, and not
   all of them are obvious issues!

3. See if there are further improvements that can be made to the code. For
   example, the way that filenames are read by the application could be
   improved. Also, the application currently doesn't support the use
   of comment lines in the header of a PGM file. You could add support for
   that.


[netpbm]: https://en.wikipedia.org/wiki/Netpbm#File_formats
