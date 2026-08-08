*This project has been created as part of the 42 curriculum by ddi-nico*

# ft_printf

## Description

`ft_printf` is a custom reimplementation of the standard C library function `printf()`, written from scratch without using the original `printf()`, `vprintf()`, or any of their variants.

The goal of the project is to understand and practice **variadic functions** in C: how a function can accept an unknown, variable number of arguments of different types at call time, and how to safely walk through them using `va_list`, `va_start`, `va_arg`, and `va_end`.

The function replicates the behavior of the original `printf()` for the following conversions, as required by the mandatory part of the subject:

| Conversion | Description                                   |
|------------|------------------------------------------------|
| `%c`       | Single character                                |
| `%s`       | String (prints `(null)` if the pointer is NULL) |
| `%p`       | Pointer address, in hexadecimal (`0x...`)       |
| `%d`, `%i` | Signed decimal integer                          |
| `%u`       | Unsigned decimal integer                        |
| `%x`       | Unsigned hexadecimal, lowercase                 |
| `%X`       | Unsigned hexadecimal, uppercase                 |
| `%%`       | Literal percent sign                            |

Flags, field width, precision, and length modifiers (bonus part) are **not implemented** in this version — only the mandatory conversions listed above are handled.

## Instructions

### Compilation

The project builds a static library, `libftprintf.a`, at the root of the repository.

```bash
make        # builds src/libft/libft.a, then libftprintf.a at the project root
make clean  # removes object files (project and libft)
make fclean # removes object files and the compiled libraries
make re     # fclean + all
```

The library is built with `cc -Wall -Wextra -Werror`, using `ar` (no `libtool`).

### Usage in another project

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s! You are %d years old.\n", "42", 21);
    ft_printf("Pointer: %p, hex: %x / %X, percent: %%\n", &main, 255, 255);
    return (0);
}
```

Compile and link against the library:

```bash
cc -Iincludes main.c -L. -lftprintf -o my_program
```

## Resources

Classic references used to understand the topic:

- `man 3 printf` — behavior of the original function, used as the reference to match output against (e.g. `(null)` and `(nil)` handling on Linux/glibc).
- C99 standard, §6.7.8 (designated initializers) and §7.15 (`<stdarg.h>`) — used to understand variadic argument handling and default argument promotions.
- 42 Norm documentation — used to keep code style compliant throughout the project.

**AI usage disclosure:** AI assistants were used along the project to understand the possible way to structure the logic (here dispatcher table with rray of function pointers indexed by characters is used), to analyze edge cases, to understand new concept (base of number), to prepare a defense. In addition, to receive an help drafting this README file, and the MAKEFILE.

## Algorithm and data structure choices

**Table-driven dispatch.** Instead of a long `if`/`else if` chain, `ft_print_dispatcher` uses a `static const` array of 256 function pointers (`t_ptr_funct conversion_list[256]`), indexed directly by the ASCII value of the character following `%`. This was chosen because:
- lookup is O(1) regardless of how many conversions are supported;
- extending the project (e.g. adding a bonus conversion) only requires adding one entry to the table and writing the matching function, without touching the dispatch logic;
- `static` ensures the table is built only once across all calls to `ft_printf`, not re-initialized on every call.

**`va_list` passed by pointer.** All conversion functions receive `va_list *args` rather than `va_list` by value. This is because `va_arg` mutates the internal state of the list as it consumes arguments; passing `va_list` by value does not portably guarantee that this progression is visible to the caller once the function returns. Passing a pointer avoids relying on this undefined/implementation-defined behavior.

**Recursive number-to-base conversion (`ft_putnbr_base`).** Numbers are converted to any base (10, 16, ...) without any temporary buffer or array: the function divides the number by the base and recurses until the quotient is smaller than the base, then prints digits as the recursion unwinds — from most significant to least significant. The call stack itself acts as the buffer that reverses digit order, which avoids manual buffer management (explicitly disallowed for the original `printf()`'s internal buffering, and a clean way to avoid it here too).

**`int` → `long` promotion for `%d`/`%i`.** Before negating a negative number, the function copies the `int` value into a `long`. This avoids undefined behavior on `INT_MIN`, whose absolute value is not representable as a positive `int` (`-INT_MIN` overflows `int` but fits in a 64-bit `long`).

**Fast path for strings without `%`.** If the format string contains no `%` at all, `ft_printf` performs a single `write()` of the whole string instead of looping character by character, reducing the number of syscalls in the common case.

**libft integration.** As allowed by the subject, this project reuses `ft_strlen` and `ft_strchr` from a full copy of libft (`src/libft/`, with its own `Makefile`), rather than reimplementing them locally. The project's `Makefile` builds `libft.a` first, then links it into `libftprintf.a`.
