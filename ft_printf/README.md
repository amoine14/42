*This project has been created as part of the 42 curriculum by amoine.*

# ft_printf

## Description

The goal of this project is to recreate the behavior of the standard C `printf()` function.

The implementation supports the following conversions:

- `%c` — Character
- `%s` — String
- `%p` — Pointer address
- `%d` / `%i` — Signed integer
- `%u` — Unsigned integer
- `%x` / `%X` — Hexadecimal integer
- `%%` — Percent sign

The bonus implementation also supports field width, precision, and the following flags:

- `-` — Left alignment
- `0` — Zero padding
- `.` — Precision
- `#` — Alternate form
- `+` — Force sign
- ` ` — Space before positive numbers

The project generates a static library named `libftprintf.a`, which also includes the required Libft functions.

## Instructions

### Compilation

Compile the mandatory part:

```bash
make
```

Compile with bonus features:

```bash
make bonus
```

Other available commands:

```bash
make clean
make fclean
make re
```

### Usage

Include the header:

```c
#include "ft_printf.h"
```

Example:

```c
int main(void)
{
    ft_printf("Hello, %s!\n", "42");
    ft_printf("Number: %d\n", 42);
    ft_printf("Hexadecimal: %x\n", 255);
    return (0);
}
```

Compile using:

```bash
cc main.c libftprintf.a -o program
```

## Implementation

The implementation is divided into several components:

1. Format parsing and conversion detection.
2. Variadic argument handling using `va_list`.
3. Integer, hexadecimal, pointer, and text output functions.
4. Bonus formatting with width, precision, and flags.
5. Error handling and character counting.

The project uses the `write()` system call to produce output.

## Resources

- C standard library documentation
- `printf(3)` manual
- `stdarg(3)` documentation
- 42 project subject

AI tools were used to assist with debugging, test generation, and implementation review. The project was developed and tested throughout the learning process.