*This project has been created as part of the 42 curriculum by fsalvucc.*

# libft

## Description

`libft` is a custom C library that reimplements a selection of standard libc
and BSD libc functions (without the `restrict` qualifier), along with
additional helper functions that are not part of the original libraries or
that behave differently. The goal is to build a personal, reusable toolbox of
core functions to rely on throughout the 42 curriculum.

## Instructions

Compile the library with `make`:

```sh
make          # compile libft.a
make clean    # remove object files
make fclean   # remove object files and libft.a
make re       # fclean + make
```

To use the library in a project, include the header and link the archive:

```c
#include "libft.h"
```

```sh
cc main.c -L. -lft
```

To test `ft_strlcpy`, `ft_strlcat`, and `ft_bzero` against the system standard
and compare them with the originals, link with the `-lbsd` flag to include the
correct library.

## Function List

- Character checks / conversion: `ft_isalpha` `ft_isdigit` `ft_isalnum`
  `ft_isascii` `ft_isprint` `ft_toupper` `ft_tolower`
- Memory: `ft_bzero` `ft_memset` `ft_memcpy` `ft_memmove` `ft_memchr`
  `ft_memcmp` `ft_calloc`
- Strings: `ft_strlen` `ft_strchr` `ft_strrchr` `ft_strncmp` `ft_strnstr`
  `ft_strdup` `ft_strlcpy` `ft_strlcat` `ft_substr` `ft_strjoin` `ft_strtrim`
  `ft_split` `ft_strmapi` `ft_striteri`
- Conversion: `ft_atoi` `ft_itoa`
- Output (fd): `ft_putchar_fd` `ft_putstr_fd` `ft_putendl_fd` `ft_putnbr_fd`
- Linked lists: `ft_lstnew` `ft_lstadd_front` `ft_lstadd_back` `ft_lstsize`
  `ft_lstlast` `ft_lstdelone` `ft_lstclear` `ft_lstiter` `ft_lstmap`

## Resources
- Linux manual pages (`man 3) for the libc original function.
- BSD manual pages for the BSD function `strlcpy `strlcat.

**AI usage:** An AI assistant was used mainly to explain concepts — clarifying
the expected behaviour of certain functions, edge cases, and Makefile rules.
The implementation, testing, and final code were done by me.
