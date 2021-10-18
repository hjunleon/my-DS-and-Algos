The goal of this exercise is to let you practice processing
and manipulating strings in C.  Try to solve this problem
directly without using any C library functions from
`string.h`.

Your program must not assume any limit to the length of the
input strings (except that their length can fit into the type 
`size_t`).

Make sure that your program runs without any illegal memory
access or memory leaks.

You will find the functions `cs1010_read_word()` and  
`cs1010_read_line()` useful.  Read the CS1010 library 
documentation on these functions carefully.

https://nus-cs1010.github.io/2122-s1/library.html#reading-of-a-single-value

You should also document the functions you write (except `main`) 
with a block of comments according to Doxygen format.  See 

https://nus-cs1010.github.io/2122-s1/documentation.html


# Question 1: Length
--------------------

Write a program `length` that reads a line of text from
the standard input and print the number of characters
in the line (including the newline character) to the
standard output.

The goal of this exercise is to let you practice processing
and manipulating strings in C.  Try to solve this problem
directly without using any C library functions from
`string.h`.

### Sample Run

```
ooiwt@pe101:~$ ./length
Hello world!
13
```


# Question 2: Concat
--------------------

Write a program `concat` that reads two words from the 
standard input, append them into a new string, and then
print a new string, to the standard output.

### Sample Run

```
ooiwt@pe101:~$ ./concat
cs
1010
cs1010
```


# Question 3: Search
--------------------
Write a program `search` that reads two words S1 and S2 
from the standard input.  If S2 is a substring of S1, then
print the position of the first occurrence of S2 within S1.
The first character in S1 has position 0. The second character 
has position 1, etc.  If S2 is not a substring of S1, then
print the string "not found".

### Sample Runs

```
ooiwt@pe101:~$ ./search
haystack
needle
not found
ooiwt@pe101:~$ ./search
haystack stack
3
ooiwt@pe101:~$ ./search
........ .
0
```
