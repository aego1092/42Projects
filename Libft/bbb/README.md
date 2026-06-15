*This project has been created as part of the 42 curriculum by giupalum.*

# Libft

## Description

Libft is the first project of the 42 Common Core. The goal is to build a personal C
library — `libft.a` — by reimplementing from scratch a selection of standard C library
functions, plus a set of additional utility functions and functions to manipulate
singly linked lists.

The purpose is twofold: to understand how the fundamental functions of the C standard
library actually work by implementing them yourself, and to start a reusable toolkit
that will be useful throughout the rest of the curriculum.

Every function is written in C, follows the 42 Norm, compiles with the flags
`-Wall -Wextra -Werror` using `cc`, and manages memory with no leaks.

## Instructions

### Build

The project uses a `Makefile`. Available rules:

| Rule | Description |
|------|-------------|
| `make` / `make all` | Compiles the sources and creates `libft.a`. |
| `make clean` | Removes the object files. |
| `make fclean` | Removes the object files and `libft.a`. |
| `make re` | Runs `fclean` then `all` (full rebuild). |

### Usage

Include the header in your source and link the library when compiling your program:

```c
#include "libft.h"
```

```bash
cc main.c -L. -lft -o my_program
# or, linking the archive directly:
cc main.c libft.a -o my_program
```

## Library content

### Part 1 — Libc functions
Reimplementations of standard libc functions, prefixed with `ft_`:

- **Character checks:** `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
- **String handling:** `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`
- **Memory handling:** `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`
- **Conversions:** `ft_toupper`, `ft_tolower`, `ft_atoi`

### Part 2 — Additional functions
Functions that are not part of the libc, or exist in a different form:

- `ft_substr`, `ft_strjoin`, `ft_strtrim` — extract a substring, concatenate, trim a set of characters
- `ft_split` — split a string into a NULL-terminated array of words using a delimiter
- `ft_itoa` — convert an integer into its string representation
- `ft_strmapi`, `ft_striteri` — apply a function to each character of a string (with its index)
- `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd` — write to a file descriptor

### Part 3 — Linked lists
Functions to create and manipulate a singly linked list built on the `t_list` structure:

- `ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back` — create a node and add nodes to a list
- `ft_lstsize`, `ft_lstlast` — count the nodes / return the last node
- `ft_lstdelone`, `ft_lstclear` — free a single node / free the whole list
- `ft_lstiter`, `ft_lstmap` — apply a function to each node's content (in place / into a new list)

## Resources

- The `man` pages of the original functions (`man strlen`, `man memcpy`, `man atoi`, ...)
- *The C Programming Language* — Kernighan & Ritchie
- The 42 Norm documentation

### Use of AI

AI (Claude) was used as a learning-support tool, **not** as the author of the code.
In particular it was used:

- to find community testers and learn how to use them.
- learning support
- Write README :)

All the functions were implemented by me. AI was used to deepen my understanding and to
verify my own reasoning, never to generate the solutions.