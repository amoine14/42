*This project has been created as part of the 42 curriculum by amoine.*

# Libft

## Description

Libft is the first project of the 42 curriculum. Its objective is to create a personal C library by reimplementing functions from the standard C library and developing additional utility functions.

The project focuses on understanding how fundamental C functions work internally, particularly regarding pointers, memory management, string manipulation, dynamic allocation, and linked lists.

The resulting static library, `libft.a`, is intended to be reused throughout future projects at 42.

## Library Overview

The library is divided into several categories of functions.

### 1. Character Classification and Conversion

These functions reproduce the behavior of common character-handling functions:

- `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`: Character classification.
- `ft_toupper`, `ft_tolower`: Character case conversion.

### 2. String Manipulation

These functions provide operations for analyzing and manipulating null-terminated strings:

- `ft_strlen`: Calculates string length.
- `ft_strchr`, `ft_strrchr`: Searches for characters.
- `ft_strncmp`: Compares strings up to a specified length.
- `ft_strlcpy`, `ft_strlcat`: Performs size-bounded copying and concatenation.
- `ft_strnstr`: Searches for a substring within a limited length.
- `ft_strdup`: Duplicates a string.
- `ft_substr`: Extracts a substring.
- `ft_strjoin`: Concatenates two strings into a new allocation.
- `ft_strtrim`: Removes specified characters from both ends of a string.
- `ft_split`: Splits a string using a delimiter.
- `ft_strmapi`, `ft_striteri`: Applies a function to string characters.
- `ft_atoi`: Converts a string into an integer.

### 3. Memory Manipulation and Allocation

Functions for working with raw memory and dynamic allocations:

- `ft_memset`, `ft_bzero`: Initializes or clears memory.
- `ft_memcpy`, `ft_memmove`: Copies memory blocks, including overlapping regions with `ft_memmove`.
- `ft_memchr`: Searches for a byte in memory.
- `ft_memcmp`: Compares memory blocks.
- `ft_calloc`: Allocates zero-initialized memory.

### 4. File Descriptor Output

Functions for writing data to a specified file descriptor:

- `ft_putchar_fd`: Writes a character.
- `ft_putstr_fd`: Writes a string.
- `ft_putendl_fd`: Writes a string followed by a newline.
- `ft_putnbr_fd`: Writes an integer.

### 5. Linked Lists

Functions for manipulating singly linked lists using the `t_list` structure:

- `ft_lstnew`: Creates a new node.
- `ft_lstadd_front`, `ft_lstadd_back`: Inserts nodes.
- `ft_lstsize`: Counts nodes.
- `ft_lstlast`: Returns the last node.
- `ft_lstdelone`: Deletes a single node.
- `ft_lstclear`: Deletes an entire list.
- `ft_lstiter`: Applies a function to each node's content.
- `ft_lstmap`: Creates a new list by applying a function to each node's content.

## Instructions

### Compilation

Clone the repository and navigate to the project directory.

Run:

```bash
make
```

This compiles the source files using:

```bash
-Wall -Wextra -Werror
```

and generates the static library `libft.a`.

### Makefile Rules

| Command | Description |
|---|---|
| `make` | Compiles the library |
| `make clean` | Removes object files |
| `make fclean` | Removes object files and the library |
| `make re` | Rebuilds the library from scratch |

### Using the Library

Include the header in your C program:

```c
#include "libft.h"
```

Compile your program and link it with the library:

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o program
```

Then execute:

```bash
./program
```

## Testing

During development, individual test programs were used to validate each function.

A comprehensive testing suite was also created to test the library as a whole.

Its purpose is to:

- Verify the behavior of every implemented function.
- Compare results with their standard library equivalents whenever available.
- Cover common inputs, edge cases, and boundary conditions.
- Check memory operations and dynamic allocations.
- Test linked list manipulation.
- Identify incorrect outputs and unexpected behavior.

Valgrind was also used during development to investigate memory leaks and memory access errors.

The complete testing suite is available separately, as described at the end of this README.

## Resources

### Documentation and References

The following resources are useful for understanding C programming, standard library behavior, and memory management:

- [C reference — cppreference](https://en.cppreference.com/w/c)
- [Linux manual pages](https://man7.org/linux/man-pages/)
- [GNU C Library Manual](https://www.gnu.org/software/libc/manual/)
- [GNU Make Manual](https://www.gnu.org/software/make/manual/)
- [Valgrind Documentation](https://valgrind.org/docs/manual/manual.html)

Manual pages such as `man 3 strlen`, `man 3 memcpy`, and `man 3 malloc` are particularly useful for understanding the expected behavior of standard C functions.

### Artificial Intelligence Usage

AI was used as a development support tool, primarily to improve testing coverage and assist with validation.

**During function development:**

AI helped generate robust `main` functions designed to test individual implementations against multiple inputs, including normal use cases and edge cases.

**For the complete testing suite:**

AI assisted in creating an extensive `test.c` file and its associated `test.h` header, designed to test the library's functions and compare their outputs against the original standard library implementations whenever applicable.

For functions without direct standard library equivalents, dedicated test cases were used to verify their expected behavior.

**For debugging and validation:**

AI was also used to discuss test scenarios, investigate unexpected results, and better understand specific behaviors related to memory, pointers, and function semantics.

The library's implementation remained a personal programming and learning exercise. AI was primarily used to support testing, debugging, and understanding rather than replace the implementation process.

## Complete Testing Suite

The complete testing suite is maintained separately from the library.

It contains:

- `test.c`: Comprehensive tests covering the implemented functions.
- `test.h`: Supporting declarations and definitions used by the testing program.

**GitHub link:** [Insert your testing repository URL here]

These files are provided as additional resources for testing and verification. They are not required to build or use `libft.a`.

## Author

**amoine** — 42 Le Havre