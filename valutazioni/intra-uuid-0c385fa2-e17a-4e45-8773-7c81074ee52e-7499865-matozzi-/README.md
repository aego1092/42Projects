*This project has been created as part of the 42 curriculum by matozzi-.*

# Description

## get_next_line

The goal of this project is to create a function that reads and returns one line at a time from a file descriptor.

The function must work with different BUFFER_SIZE values and handle files of different sizes. It uses a static variable to store remaining data between function calls.

# Instructions

## Compilation

Compile the project with:

make

Clean object files:

make clean

Remove all generated files:

make fclean

Recompile:

make re

## Usage

Include the header file:

#include "get_next_line.h"

Example:

char *line;

line = get_next_line(fd);

The function returns the next line from the given file descriptor each time it is called.

# Algorithm

The algorithm uses a static variable called stash to store data that has been read but not yet returned.

The steps are:

1. Read data from the file descriptor using read().
2. Add the new data to stash.
3. Continue reading until a newline is found or the end of the file is reached.
4. Extract the first line from stash.
5. Update stash by removing the returned line and keeping the remaining data.
6. Return the extracted line.

This method allows the function to manage large files and different BUFFER_SIZE values while keeping unread data between calls.

The static variable is necessary because get_next_line() needs to remember the remaining content after each call.

# Resources

## References

- read() manual page:
  https://man7.org/linux/man-pages/man2/read.2.html

- C documentation:
  https://en.cppreference.com/

- 42 Network documentation and peer discussions.

## AI Usage

AI was used as a learning assistant during this project.

It was used for:
- Understanding concepts about memory allocation and file reading.
- Debugging errors and segmentation faults.
- Reviewing the algorithm and improving code structure.
