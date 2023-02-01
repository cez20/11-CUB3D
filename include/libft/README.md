# Libft
This project aims to code a C library regrouping usual functions that can be used in all other 42 projects.

📄 [Subject PDF v. 15](https://github.com/anasilvr/Libft/blob/main/en.subject.pdf)

The content of this repository is subject to constant change as new general functions developed during other projects are added here.

## Makefile 🔨
| Command | Usage |
| --- | --- |
| `make` | creates .o files for each function as well as the main library file, libft.a |
| `make clean` | removes the .o files used to create the library |
| `make fclean` | removes the .o & .a files used to create the library |
| `make re` | removes all .o & .a files then remakes them |

## Files 
<details><summary>:file_folder: GNL</summary>
  
| Function | Description |
| --- | --- |
| [get\_next\_line.c](https://github.com/anasilvr/Libft/blob/main/GNL/get_next_line.c) | returns a line read from a file descriptor|
</details>


<details><summary>:file_folder: ft_printf</summary>
  
| Function | Description |
| --- | --- |
| [ft\_printf.c](https://github.com/anasilvr/Libft/blob/main/ft_printf/ft_printf.c) | prints to STDOUT and returns an int value equal to the number of printed chars (%cspduxX)|
</details>


<details><summary>:file_folder: io</summary>
 
| Function | Description |
| --- | --- |
| [ft\_putchar\_fd.c](https://github.com/anasilvr/Libft/blob/main/io/ft_putchar_fd.c) | outputs a character to the given file descriptor|
| [ft_putendl_fd.c](https://github.com/anasilvr/Libft/blob/main/io/ft_putendl_fd.c) | outputs a string to the given file descriptor followed by a \n|
| [ft_putnbr_fd.c](https://github.com/anasilvr/Libft/blob/main/io/ft_putnbr_fd.c) | outputs an integer to the given file descriptor|
| [ft_putstr_fd.c](https://github.com/anasilvr/Libft/blob/main/io/ft_putstr_fd.c) | outputs a string to the given file descriptor|
</details>


<details><summary>:file_folder: lists</summary>

| Function | Description |
| --- | --- |
| [ft_lstadd_back.c](https://github.com/anasilvr/Libft/blob/main/lists/ft_lstadd_back.c) | adds a new element at the end of the list|
| [ft_lstadd_front.c](https://github.com/anasilvr/Libft/blob/main/lists/ft_lstadd_front.c) | adds a new element at the beginning of the list|
| [ft_lstclear.c](https://github.com/anasilvr/Libft/blob/main/lists/ft_lstclear.c) | deletes and frees the given element and every successor of that element|
| [ft_lstdelone.c](https://github.com/anasilvr/Libft/blob/main/lists/ft_lstdelone.c) | deletes and frees the given element|
| [ft_lstiter.c](https://github.com/anasilvr/Libft/blob/main/lists/ft_lstiter.c) | iterates through a list while applying the function passed to the content of each element|
| [ft_lstlast.c](https://github.com/anasilvr/Libft/blob/main/lists/ft_lstlast.c) | returns the last element of the list|
| [ft_lstmap.c](https://github.com/anasilvr/Libft/blob/main/lists/ft_lstmap.c) | iterates through a list while applying the function passed to the content of each element and creating a new list with the results|
| [ft_lstnew.c](https://github.com/anasilvr/Libft/blob/main/lists/ft_lstnew.c) | allocates (with malloc(3)) and returns a new element|
| [ft_lstsize.c](https://github.com/anasilvr/Libft/blob/main/lists/ft_lstsize.c) | counts the number of elements in a list|
</details>


<details><summary>:file_folder: memalloc</summary> 
  
| Function | Description |
| --- | --- |
| [free_table.c](https://github.com/anasilvr/Libft/blob/main/memalloc/free_table.c) | frees all elements of a 2d array |
| [ft_calloc.c](https://github.com/anasilvr/Libft/blob/main/memalloc/ft_calloc.c) | contiguously allocates memory that is filled with bytes of value zero|
| [ft_realloc.c](https://github.com/anasilvr/Libft/blob/main/memalloc/ft_realloc.c) | reallocates the given area of memory|
| [ft_xcalloc.c](https://github.com/anasilvr/Libft/blob/main/memalloc/ft_xcalloc.c) | same as calloc(), but it directly exits in case of memory allocation error|
| [xfree.c](https://github.com/anasilvr/Libft/blob/main/memalloc/xfree.c) | frees a pointer after checking it isn't NULL |
</details>


<details><summary>:file_folder: strings</summary> 
  
| Function | Description |
| --- | --- |
| [ft_atoi.c](https://github.com/anasilvr/Libft/blob/main/strings/ft_atoi.c) | converts ASCII string to integer|
| [ft_atol.c](https://github.com/anasilvr/Libft/blob/main/strings/ft_atol.c) | converts ASCII string to long integer |
| [ft_bzero.c](https://github.com/anasilvr/Libft/blob/main/strings/ft_bzero.c) | erases the data in the n bytes of the memory by writing '\0' to that area|
| [ft_itoa.c](https://github.com/anasilvr/Libft/blob/main/strings/ft_itoa.c) | allocates and returns a string representing the integer passed as argument|
| [ft_memchr.c](https://github.com/anasilvr/Libft/blob/main/strings/ft_memchr.c) | scans n bytes of the pointed memory for the first instance of a char|
| [ft_memcmp.c](https://github.com/anasilvr/Libft/blob/main/strings/ft_memcmp.c) | compares the first n bytes of the block of memory from 2 strings|
| [ft_memcpy.c](https://github.com/anasilvr/Libft/blob/main/strings/ft_memcpy.c) | copies n bytes from one memory area to another|
| [ft_memmove.c](https://github.com/anasilvr/Libft/blob/main/strings/ft_memmove.c) | copies n bytes from string to to another using a temporary array to handle overlap|
| [ft_memset.c](https://github.com/anasilvr/Libft/blob/main/strings/ft_memset.c) | fill a block of memory with a particular value|
| [ft_split.c](https://github.com/anasilvr/Libft/blob/main/strings/ft_split.c) | splits a string, with specified character as delimiter, into an array of strings|
| [ft_strchr.c](https://github.com/anasilvr/Libft/blob/main/strings/ft_strchr.c) | locates the first occurrence of c (converted to a char) in the string|
| [ft_strcmp.c](https://github.com/anasilvr/Libft/blob/main/strings/ft_strcmp.c) | compares (lexicographically) two strings|
| [ft_strdup.c](https://github.com/anasilvr/Libft/blob/main/strings/ft_strdup.c) | allocates sufficient memory for a copy a string copies and returns a pointer to it|
| [ft_striteri.c](https://github.com/anasilvr/Libft/blob/main/strings/ft_striteri.c) | applies the function f to each character of the string passed as argument |
| [ft_strjoin.c](https://github.com/anasilvr/Libft/blob/main/strings/ft_strjoin.c) | allocates and returns a new string (concatenation of two strings) |
| [ft_strjoin_free.c](https://github.com/anasilvr/Libft/blob/main/strings/ft_strjoin_free.c) | same as ft_strjoin(), but it frees the old string |
| [ft_strlcat.c](https://github.com/anasilvr/Libft/blob/main/strings/ft_strlcat.c) | appends two strings |
| [ft_strlcpy.c](https://github.com/anasilvr/Libft/blob/main/strings/ft_strlcpy.c) | size-bounded string copying |
| [ft_strlen.c](https://github.com/anasilvr/Libft/blob/main/strings/ft_strlen.c) | counts the numbers of characters preceding the terminating NUL-character of a string|
| [ft_strmapi.c](https://github.com/anasilvr/Libft/blob/main/strings/ft_strmapi.c) | applies a function to each character of a string, creating a new string with the modifications|
| [ft_strncmp.c](https://github.com/anasilvr/Libft/blob/main/strings/ft_strncmp.c) | compares (lexicographically) up to n characters of two strings|
| [ft_strnstr.c](https://github.com/anasilvr/Libft/blob/main/strings/ft_strnstr.c) | locates the first occurrence of the null-terminated substring in the a string, where not more than n characters are searched|
| [ft_strrchr.c](https://github.com/anasilvr/Libft/blob/main/strings/ft_strrchr.c) | locate last occurrence of character in string|
| [ft_strtrim.c](https://github.com/anasilvr/Libft/blob/main/strings/ft_strtrim.c) | allocates and returns a copy of a string with the characters specified in ’set’ removed from the beginning and the end of the string|
| [ft_substr.c](https://github.com/anasilvr/Libft/blob/main/strings/ft_substr.c) | allocates and returns a substring from another string|
</details>


<details><summary>:file_folder: types</summary> 
  
| Function | Description |
| --- | --- |
| [ft_isalnum.c](https://github.com/anasilvr/Libft/blob/main/types/ft_isalnum.c) | tests for any character for which ft_isalpha or ft_isdigit is true|
| [ft_isalpha.c](https://github.com/anasilvr/Libft/blob/main/types/ft_isalpha.c) | tests for any character for which ft_isupper or ft_islower is true|
| [ft_isascii.c](https://github.com/anasilvr/Libft/blob/main/types/ft_isascii.c) | tests for any ASCII character between 0 and octal 0177 inclusive|
| [ft_isdigit.c](https://github.com/anasilvr/Libft/blob/main/types/ft_isdigit.c) | tests for a decimal digit character|
| [ft_isprint.c](https://github.com/anasilvr/Libft/blob/main/types/ft_isprint.c) | tests for any printing character, including space|
| [ft_isset.c](https://github.com/anasilvr/Libft/blob/main/types/ft_isset.c) | tests if the character is part of a set|
| [ft_isspace.c](https://github.com/anasilvr/Libft/blob/main/types/ft_isspace.c) | tests if a character is a white-space character|
| [ft_tolower.c](https://github.com/anasilvr/Libft/blob/main/types/ft_tolower.c) | upper case to lower case letter conversion|
| [ft_toupper.c](https://github.com/anasilvr/Libft/blob/main/types/ft_toupper.c) | lower case to upper case letter conversion|
</details>

<img align="right" width="150" alt="125/100" src="https://user-images.githubusercontent.com/91762843/208724476-e401aed6-c5f2-4a93-a72c-7647236032ea.png">


