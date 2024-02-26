<h1 align="center">42_get_next_line</h1>

<p align="center">
  <a href="#about">About</a> &#xa0; | &#xa0;
  <a href="#usage">Usage</a> &#xa0; | &#xa0;
  <a href="#notes">Notes</a> &#xa0; | &#xa0;
  <a href="#allowed-functions">Allowed functions</a> &#xa0; | &#xa0;
  <a href="https://github.com/Szabold1" target="_blank">Author</a>
</p>

<br>

## About

The get_next_line project is a function designed to read text from a file descriptor one line at a time. It allows for repeated calls, enabling the sequential reading of a file until the end or an error occurs. This function is particularly useful for parsing text data from files or standard input.

## Usage

To test the functionality of `get_next_line()`, you can comment out the main function inside `get_next_line.c`. Once commented out, compile the code using the following format:

```shell
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_utils.c get_next_line.c
```

Replace BUFFER_SIZE=42 with your desired buffer size.

## Notes

- `BUFFER_SIZE` determines the amount of data read from the file descriptor in each iteration.
- Free dynamically allocated memory for each line returned by `get_next_line()` to prevent memory leaks.

## Allowed functions

The following functions were allowed for use in this project:

| **Function** | **Man**      | **Short Description**                   |
| ------------ | ------------ | --------------------------------------- |
| read         | man 2 read   | Reads data from a file descriptor       |
| malloc       | man 3 malloc | Allocates a block of memory dynamically |
| free         | man 3 free   | Deallocates a block of memory           |

<br>

<div align="center">
  Made by <a href="https://github.com/Szabold1" target="_blank">Boldizsar Szabo</a>
</div>
