This question is meant to be a giveaway.

Given a 3x3 2D array, you only need to scan through each row, each column, and each diagonal, to see if a given player has marked all three cells.

```
/**
 * Check if a given player has won.
 *
 * @param[in] ttt The tic-tac-toe game board
 * @param[in] player The player to check
 *
 * @return true if the player has won.  false 
 * otherwise.
 */
bool has_won(char *ttt[3], char player) {
    // check row
    for (long row = 0; row < 3; row += 1) {
       if (ttt[row][0] == player && 
           ttt[row][1] == player && 
           ttt[row][2] == player) {
           return true;
       }
    }
    // check col
    for (long col = 0; col < 3; col += 1) {
       if (ttt[0][col] == player && 
           ttt[1][col] == player && 
           ttt[2][col] == player) {
           return true;
       }
    }
    // check diagonal
    if (ttt[0][0] == player && 
        ttt[1][1] == player && 
        ttt[2][2] == player) {
       return true;
    }
    if (ttt[0][2] == player && 
        ttt[1][1] == player && 
        ttt[2][0] == player) {
       return true;
    }
    return false;
}
```

Comments after grading: Many students appeared to have difficulties answering this question after PE2 (one commented spending an hour on this) and the teaching team is puzzled about why. After grading, however, it is clear that most students solve this problem the hard way, taking an overly complicated approach and ignoring the requirement of the question given to help you.

### Using variable size array

One way we simplify this 2D array question (compared to 18/19) is to use a square 2D array and a fixed size 2D array. Having a fixed size 2D array means that you can declare your array with size of 3, and therefore no need to check for NULLs and free the array after use. This significantly reduces the amount of code that you need to write.

Compare

```
char *board[3];
```

to

```
char **board;
board = malloc(sizeof(char *) * 3);
if (board == NULL) {
  // print something
  return 1;
}
  :
  :
free(board);
```

### Writing a `has_won` method.

The question asked for a `has_won` method that takes in the player as a parameter and determines if the given player has won. Many students do not follow this, but instead, try to solve the problem in their own way.

One approach is to pass the player by reference, look for the winner in `has_won`, and set the winner instead. This could lead to several possible bugs. Some students incorrectly look for three same characters in a row and included `?` as a possible winner (this would not have happened if you follow the question, since ‘?’ is not a player!). The other approach is that, instead of taking in a player as an argument, some students replicated the logic to check for `X` and `O` within `has_won`. This resulted in many lines of cut-and-paste code, and when students do not cut-and-paste and replace ‘X’ with ‘O’ correctly, bugs ensue.

### Unnecessary Variables

Many students introduced unnecessary variables, complicated the code and obfuscating the logic. For instance,

```
// check row
    int i = 0;
    for (long row = 0; row < 3; row += 1) {
       if (ttt[row][i] == player && 
           ttt[row][i + 1] == player && 
           ttt[row][i + 2] == player) {
           return true;
       }
    }
```

Since `i` is never changed, this variable is redundant. The more variables you used, the higher the likelihood that you introduce bugs. Indeed several students got caught by this.

### Logical Expressions

To check if more than two variables are the same, you cannot write something like

```
if (ttt[row][i] == ttt[row][i + 1] == ttt[row][i + 2] == player)
```

You should use the `&&` operator.

### Memory Leaks

Many students still do something like this:

```
board[i] = malloc(3);
board[i] = cs1010_read_word();
```

causing memory leaks. Please read https://nus-cs1010.github.io/2021-s1/18-heap.html#manual-memory-allocation-deallocation again.


# Sun

This is meant to be another easy question that we expect most students to be able to answer.  There are several approaches we can solve this.

Given n, we wish to find two numbers that adds up to n, one is either 0 or a prime, the other is either 0 or a triangular number.

## Approach 1

A naive approach is the following:

```C
for (long i = 0; i <= n; i += 1) {
	if (is_triangular(n-i) && is_prime(i)) {
		// output i and n-i
	}
}
```
where `is_prime` is the usual prime checker (but treating 0 as prime) and `is_triangular` is a new function that checks if a number is a triangular number.

How can we check if a number is a triangular number?   This is not trivial and requires a bit of high-school mathematics.  A triangular number is in the form of `x*(x+1)/2` for integer x.  Given a number k, to check if `x(x+1)/2 = k` for some integer k, we need to solve the quadratic equation, to find if the root to the equation above is an integer.  But, finding the root involves floating point operations and `double` might not accurately represent an integer!

## Approach 2

We actually don't need to check if a number is a triangular or not.  Unlike prime, where there is no formula to describe a prime, a tringular number can be generated by the formula $$\frac{x(x+1)}{2}$$.  So, we can generate all triangular numbers, and check:

```C
long tri = 0;
for (long x = 0; tri <= n; x += 1) {
	tri = x*(x+1)/2;
	if (is_prime(n - tri)) {
		// output tri and n - tri
	}
}
```

This algorithm is rather straight forward, but there is one issue, we need to print the primes in increasing order, and the code above does the opposite.

One way to fix it is to reverse the order where we generate the triangular number.
We can start with the largest trigular number less than n.

```C
long tri = 0;
long max;
// find the smallest triangular number > n
for (max = 0; tri <= n; max += 1) {
	tri = max*(max+1)/2;
}
// step through triangular numbers in decreasing order.
for (long x = max - 1; x >= 0; x -= 1) {
	tri = x*(x+1)/2;
	if (is_prime(n - tri)) {
		// output tri and n - tri
	}
}
```

The running time for this approach is O(n) as required.  The first for loop above is $$O(\sqrt{n})$$.  In the second for loop, since there are $$O(\sqrt{n})$$ triangular numbers, we call `is_prime` $$O(\sqrt{n})$$ times, and each `is_prime` invocation is $$O(\sqrt{n})$$.

## Approach 3

The third approach tries to fix the reverse order of printing in another way.  We have seen how to reverse a number recursively in PE1.  We can use the same trick here.

```
void sun(long n, long x) {
	long tri = x*(x+1)/2;
	if (tri > n) {
		return;
	}

	// print the rest
	sun(n, x+1);

	// print this pair if sums to n
	if (is_prime(n - tri)) {
		// output tri and n - tri
	}
}
```

We call `sun` at most $$O(\sqrt{n})$$ time, and each call involved `is_prime` which is $$O(\sqrt{n})$$ time.  So it works out to be $$O(n)$$.

 Common Errors

## General

- When solving a problem, it is important to consider the boundary cases.  In the context of loops, this requires checking for the loop initialization and termination condition carefully.  Many students produced bugs that involves wrong initialization (should it be 0, 1, or 2?) or termination condition (should it be `< ` or `<=`?).

## Checking if a Number is Prime

- Many students treat 1 as a prime number.  1 is not prime!

- Surprisingly, despite having gone through how to check for primes many times, including a question specifically on the intricacy of the loop conditions for prime checking in midterm, a number of students still do not do this correctly.

## Checking if a Number is Triangular

As mentioned above, triagular number is something that we can generate with a formula, unlike prime.  Some students went for a solution that checks if a given number is a tringular number, with a code that looks like this.

```
for (long i = min; i <= max; i += 1 {
	if (i*(i+1)/2 == n) {
		return true;
	}
}
return false;
```

We can set `min` to 0, to handle to special case of treating 0 as a triangular number.  But many students incorrectly set `max` to `sqrt(n)` -- perhaps to emulate the checks for prime or perhaps due to the question stating that there are $$O(\sqrt(n))$$ triangular numbers.  This is too small and it will not correctly check all possible triangular number.  There is no mathematical basis for giving $$\sqrt{n}$$ as the bound for `i`.

If you do the math, you will find that max should be $$\frac{\sqrt{8n+1}-1}{2}$$.  You can also bound it with $$\sqrt{2n}$$.

## Efficiency

Many students gave a $$O(n\sqrt{n})$$ solution, which looks something like:
```
for (long i = 0; i <= n; i += 1) {
	if (is_prime(i) && is_triangular(n - i)) {
		// print pair
	}
}
```
You will loose 3 marks for efficiency.

Note that even if we accept $$O(n\sqrt{n})$$ solution, the order of checking for prime and triangular matters -- we should check the faster one first.  If you have a $$O(1)$$ algorithm for checking triangular number, you should check that first, before checking for prime, which is $$O(\sqrt{n})$$, to take advantage of short circuting and avoid redundant work.

# Replace

This question is not as straight forward, but it builds on top of the needle and the haystack problem set question.

The following is the code to search for the needle (`search_for`) in the haystack (`word`), starting at position i in `word`.

```C
bool is_match(char *word, size_t i, char *search_for)
{
    size_t word_len = strlen(word);
    size_t search_len = strlen(search_for);
    size_t j = 0;
    for (j = 0; j < search_len && i + j < word_len; j += 1) {
        if (word[i + j] != search_for[j] ) {
            return false;
        }
    }
    if (j == search_len) {
        return true;
    }
    return false;
}
```

Suppose we found the target substring to search for, we can override the characters in `word`, starting from position i, by copying the replacement
substring into `word`.

```C
void substitute(char *word, size_t i, size_t target_len, char *replace_with) {
    size_t replace_len = strlen(replace_with);
    size_t j = 0;
    while (j < replace_len) {
        word[i + j] = replace_with[j];
        j += 1;
    }
	 :
}
```

So far, things are pretty straightforward.  The more involved part is this: Since the replacement can be shorter than the target, what do we do with the remnants of the target string?  Suppose we have `aaabbbccc` and we want to replace `bbb` with `_`, `word` becomes `aaa_bbccc`.  What do we do with `bb`?

Approach 1: We can override the remaining `bb` with `ccc` to compact the string.

```C
void substitute(char *word, size_t i, size_t target_len, char *replace_with) {
    size_t replace_len = strlen(replace_with);
    size_t j = 0;
    while (j < replace_len) {
        word[i + j] = replace_with[j];
        j += 1;
    }
	// j now points to the end of the replacement string
	size_t word_len = strlen(word);
	while (i + target_len < word_len) {
		word[i + j] = word[i + target_len];
		i += 1;
	}
    word[i + j] = 0;
}
```

This will give us the correct out, but it will result in lots of redundant work in copying the remaining of the string, if there are multiple instances of the target substring to replace.

Imagine we have the string `aaaaa......a` of length n, and we are replacing `aa` with `b`.  After the first replacement, we have to copy $$n - 2$$ times.  After the second replacement, we have to copy $$n - 4$$ times, etc.  This leads to a $$O(n^2/k)$$ run time.

In fact, many of the copy above is redundant, and we hope that students can realize this point.

To be efficient, we only need to compact the string once after we replace all the instances of target with the replacement.

Approach 2: We mark the remaining `bb` as removed, without compacting the string.

This approach is similar to some students have used on the `mastermind` problem.  We can have a second boolean array to mark if a character is removed, or just replace the character with something that never appears in the original string.  Since the string is guaranteed not to contain white spaces, in the code below, we simply replace `bb` with white spaces.


```C
void substitute(char *word, size_t i, size_t target_len, char *replace_with) {
    size_t replace_len = strlen(replace_with);
    size_t j = 0;
    while (j < replace_len) {
        word[i + j] = replace_with[j];
        j += 1;
    }
    while (j < target_len) {
        word[i + j] = ' ';
        j += 1;
    }
}
```

When all the subsitution is done, we go through the string one more time and remove all the spaces.

```
void compact(char *word)
{
    size_t src = 0;
    size_t dst = 0;
    size_t word_len = strlen(word);

    while (src < word_len) {
        if (word[src] != ' ') {
            word[dst] = word[src];
            dst += 1;
        }
        src += 1;
    }
    word[dst] = 0;
}
```

The last step takes $$O(n)$$ time, so is within the bound of $$O(nk)$$.


Putting everything together, we have:
```
void replace(char *word, char *search_for, char *replace_with)
{
    size_t word_len = strlen(word);
    size_t search_len = strlen(search_for);
    for (size_t i = 0; i < word_len; i += 1) {
        if (is_match(word, i, search_for)) {
            substitute(word, i, search_len, replace_with);
            i += search_len - 1;
        }
    }
	compact(word);
}
```

## Comments After Grading

This question is meant to be manageable by most students.  Three functions, about 10 lines each, suffices to solve the problem.  We notice that, however, many students wrote long and complex functions, most of it is due to "self-inflicted" complexity.  Some of the common unnecessary code written by students are:

- read in the string to be replaced and its replacement as a line of text, then parse the string looking for spaces, to determine which part of the line is the string to be replaced and which part of the line is the replacement.  This step is not needed if the students use `cs1010_read_word()` to read in two words directly.

- read in the list of string to be replaced and its replacement into an array of strings.  This array has to be a dynamic array, and so using it comes with all the work you need to manage the memory properly (checks for NULL, free after use, free the past allocated memory if NULL, etc.)  Doing so immediately increases the complexity of the solution up a notch.  Storing into an array is not needed, since after you are done with the replacement, you are not going to use it anymore.  So, the two strings can just be stored into two variables.  The two variables can be reused for the next pair.

- use a temporary string to store the result after replacement.  This is also unnecessary since the new string is guaranteed to be of equal length or shorter.  Students who use a temporary string has to dynamically allocate the memory for it, and so has to do all the work to manage its memory and remember to free it after used.  Furthermore, since multiple replacements maybe needed, this becomes a common source for bug -- the second replacement needs to be done on the temporary string, not the original string.

## Marking Schemes

For memory management, you need to at least checks for NULL and free the dynamically allocated memory to score 1 point.  If you do some of that but missed out a few, you are awarded 2 marks.  A perfect memory management code (no leaks even when malloc fails) is needed for 3 marks.

For efficiency, you need to be close to the correct solution to get the 2 marks.  Note that, the intricacy of the efficiency comes from dealing with what happened with the replacement is shorter (whether you copy after every replacement or after all the replacement is done).  So, if your solution does not deal with this situation, it is considered not close enough to the solution and no efficency mark will be given.

# Soil

This is another easy question to score partial marks on correctness.

The naive $$O(mn)$$ approach is to scan the 2D array with two for loops to look for a query.  This would guarantee you 5 marks.  This is kind of a give away too (easier to get than 6 marks of `tictactoe` I would say)

If you work a little bit more, you can get 8 marks, with a $$O(m log n)$$ algorithm: For each row, do a binary search for the query.  This should also be easy since the algorithm for binary search can be applied directly without any change.

We expect most students to be able to get at least 5 - 8 marks given how easy it is.

Getting the last 3 marks, you need a $$O(m + n)$$ solution.  This is a bit harder but we expect the As students can solve it.

Note that the $$O(mn)$$ solution above does not exploit the fact the the 2D array is "row-sorted" and "column-sorted".  The $$O(m log n)$$ solution only exploits the fact that the 2D array is sorted in every row.  To get $$O(m + n)$$, we need to use the fact that it is sorted in every row and every column.

This can be done by starting from the top-right corner (or bottom right), and compare `a[0][n-1]` with the query `q`.  Initially, the search area is the whole 2D array.  We incrementally reduce the search area.  If `q` is larger than `a[0][n-1]`, what can we know about where `q` is?  Since every row is sorted, we know that it cannot be in the first row.  We update the top-left corner of the search area to be `a[1][n-1]`.  On the other hand, if `q` is smaller than `a[0][n-1]`, we know that `q` cannot be in the right-most column.  We update the top-left corner of the search area to `a[0][n-2]`.

So, every comparison, we shrink the search area by one row or by one column.  It only takes $$O(m + n)$$ until we search the whole 2D array.

Here is what the code looks like:

```
void search(long *a[], long nrows, long ncols, long q) {
    long i = 0;
    long j = ncols - 1;
    while (i < nrows && j >= 0) {
        if (a[i][j] > q) {
            j -= 1;
        } else if (a[i][j] < q)
            i += 1;
        } else {
           cs1010_print_long(i);
           cs1010_print_string(" ");
           cs1010_println_long(j);
           return;
        }
    }
    cs1010_print_string("not found");
}
```

## Comments

Given how easy it is to get 8 marks using binary search and 5 marks using exhaustive search, it is surprising that less than 35 students received 5 marks or more.  Many students go straight for the efficient (but harder to get correct) $$O(m + n)$$ solution, but ended up with the wrong solution.

A common wrong solution is the following: given a query $$q$$, search for the row where the first element has the largest value less than $$q$$.  Then, search only in this row for $$q$$.  This is not correct.  $$q$$ can be in any row where the first element is less than $$q$$.  So you need to search every such row (leading to a $$O(mn)$$ solution).

Another common wrong solution is to immiate binary search and divide the land into four quadrants.  Then  compare the query with the plot in the middle.  Depending on whether the query is bigger or smaller, search in one of the quadrants.  This is also incorrect, since we can only eliminate one of the four quadrants for each comparision.  A correct solution using this approach would need to recursively search in the remaining three quadrants.

The point of this question is to see whether students can use the sorted properties given in the data to come up with a faster algorithm than the naive solution -- something you have seen in the searching/sorting units and Assignment 7.  This is related to pattern recognition skill in computational thinking. Despite everyone doing well in Assignment 7, students seems to be having difficulties doing so in PE2.

Similar to `replace`, there are some self-inflicted complexity in the solution, such as allocating a dynamic array to store the elements and read in the salinity one-by-one, instead of using `cs1010_read_long_array`.  Once you use a dynamic array, the complexity of your code increases significantly.

Another surprise is the number of buggy binary search I encountered.  Since this is an open book PE, I did not expect this -- just copy the one from the notes and you will be fine!

# Marking Scheme

For efficiency, an $$O(m \log n)$$ solution is worth 3 marks.  $$O(mn)$$ solution (even with some clever optimization) is 0.  A correct $$O(m + n)$$ solution will receive 6 marks.

# Substring

This question requires finding all possible substrings of length k and is
a simple tweak to the `permutation` problem.

We expect students who understand the solution to `permutation` to be able to solve this.

Recall that in `permutation` solution, we move the characters around and
then recursively permute.  This is because, permutation involves all possible
orders of the characters in the string.

In `substring`, the problem is slightly different, we maintain the order, but for each character, we may or may not include it in the substring.

Consider `abcd` and we want all substring of length 2.  If we include `a` in the substring, then we need to find all substring of length 1, for `bcd`.  If we exclude `a` in the substring, then we need to find all substring of length 2, for `bcd`.

So we need to include or exclude a character while we recurse.  We also need to keep track of how many characters have been included (or excluded).  There are multiple ways to do this.  In the following, I use a boolean array to keep track of whether a character is included or not, and a long variable k to keep track of how many characters still needs to been excluded.

```
/**
 * @param word    The original word.
 * @param chosen  A boolean array indicate if a character is included in the
 *                substring.  chosen[i] is true if word[i] is included.
 * @param remains How many characters remaining to be excluded from curr onwards.
 * @param curr    The index of the first character of the remaining string to
 *                construct the substring.
 * @param end     The last index of `word`
 */
void combine(char* word, bool chosen[], long remains, long curr, long end)
{
    if (remains == 0) {
        print(word, chosen);
        return;
    }
    if (curr != end) {
        // include curr and exclude remains from the rest
        combine(word, chosen, remains, curr+1, end);

        // exclude curr and remains-1 from the rest
        chosen[curr] = false;
        combine(word, chosen, remains-1, curr+1, end);

        // restore
        chosen[curr] = true;
    }
}
```

This recursive function is invoked with
```
  combine(word, chosen, end-k, 0, end);
```
where `chosen` is a boolean array initialzed to all `true` and `end` is `strlen(word)`.

The first base case for the recursion is when there is no more characters to exclude from the substring.  In this case, we just print out the string, using the `chosen` array as the filter.

The other base case is when `curr == end`.  In this case, we have reach the end of the string, and if `remains` is not yet 0, we can never construct a substring of size k.  We just do nothing and return 0.

For the rest of the recursion, we choose to include or exclude the current character, and then recursively generate the substrings.

The code for `print` is

```C
void print(char* word, const bool *chosen)
{
  size_t len = strlen(word);
  for (size_t i = 0; i < len; i += 1) {
    if (chosen[i]) {
      putchar(word[i]);
    }
  }
  putchar('\n');
}
```

You can further improve the code by avoiding redundant work.  Note that, if `end - curr == remains`, then all the remaining characters should be excluded to have a valid substring of length k.  So we can just exclude everything from `curr` onwards and print out the substring without a need to recurse further.

## Comments

Many students just copied the code for permutation for this question.  Some did a bit more by truncating the output from permutation to the requirement number of characters.  Finding substrings is a different problem and requires a different solution.  Even as some elements of `permute` (such as the recursion, the base case) remains, some thoughts into the relations between the two problems and how they different is required.
