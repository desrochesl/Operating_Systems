# Assignment 2

## Introduction

In this assignment, you will practice working with arrays and strings in the C programming language.

To get started, first clone from GitHub. You may need to "close" the existing folder first.

### Function Documentation

At the top of each function, you should write Javadoc-style documentation. This consists of a short
blurb of what the function is supposed to do (1—4 lines), what the parameters should be, and what
the return value would be. For example:

    /**
     * This function returns the index of the first positive number in the array.
     * @param array Pointer to the array.
     * @param alen The length of the array. Should be positive or zero.
     * @returns The index of the first positive number, or -1 if not found.
     */
    int find_first_pos(int* array, int alen);

### Build Instructions

To build this project run the `make` command in the terminal. You must run this *every time you change a file*.

### Running Unit Tests

To run the unit tests, run the following command for `array_fill`. For this assignment, each
function has it's own test file:

    ./test_array_fill

### Commit Instructions

After completing `array_fill`, first add the file called `array_fill.c` to staging:

    git add array_fill.c

Then do the actual commit:

    git commit -m 'Completed array_fill'

Do the same after every function/file completed.

When you are ready to submit the assignment, run the following command:

    git push

## Instructions

### array_fill

For this part, you will implement a function that fills the array with numbers,
from `begin` to `end`, in increasing order.

The function definition looks like the following:

    int array_fill(int *array, int array_len, int begin, int end);

Some test cases:

| array_len | begin | end | array (result) | return_value |
| --------- | ----- | --- | -------------- | ------------ |
|      2    |  11   |  12 |   {11, 12}     |         2    |
|      6    |  11   |  14 | {11,12,13,14}  |         4    |
|      2    |  11   |  14 |   {11, 12}     |         2    |
|      0    |  11   |  14 |        N/A     |         0    |
|      2    |  14   |  11 |        N/A     |         0    |

In the third case, the array will contain `{11, 12}` (because that's what can fit) and the return
value should be the number of elements filled (so with 11, 12, return 2).

In the fifth case, the array will contain nothing since the numbers should be in increasing order.

### valid_password

**NOTE**: You may use functions from the `ctype.h` header, but not from the `string.h` header. Some
functions that may be useful are those like `isupper` or `islower`.

Originally from [WC '17 Contest 3 J3] (https://dmoj.ca/problem/wc17c3j3).

You'd like to register an account on an extremely entertaining website. You've already selected a username, but it seems
that the requirements for choosing a password are quite strict, in order to completely protect your account from being
hacked into. The password must be a string between 6 and 10 characters long (inclusive), such that every character is
either a lowercase letter (a … z), uppercase letter (A … Z), or digit (0 … 9). Furthermore, it must contain at least
two lowercase letters and at least two uppercase letters.

Your task is to complete the function `valid_password`. The function takes in a password as a string, and returns `true`
if the string is valid, `false` if not.

Some test cases:

| password | return_value |
| -------- | ------------ |
|   abc    |      false   |
|   aBcdeF |      true    |

### string_fill

**NOTE**: You may use functions from the `ctype.h` header, but not from the `string.h` header.

For this part, you will work on a function that fills a string with content. You
are given a char array that you are to fill in (this is called a *destination
buffer*). You are also given the capacity of the destination buffer (also known
as the size).

You task is to fill this array with chars to make it a proper string. For
example, given an array of 9 characters and the letter 'R', you should return
"RRRRRRRR". This is **8 (eight)** Rs, not 9, since we need to contend with the
terminator character.

If `dest` is `NULL`, your code should do nothing and just return.

Some test cases:

| dest_cap | c | dest (result) |
| -------- | - | ------------- |
|       2  | S |     "S"       |
|       9  | R |  "RRRRRRRR"   |
|       1  | G |     ""        |

> [!NOTE]
> If you get the following error, this means there was an index out of bounds error in
> [string_fill.c](string_fill.c) line 23. It was called from [test_string_fill.c](test_string_fill.c) line 33.

    string_fill.c:8:13: runtime error: store to null pointer of type 'char'
    AddressSanitizer:DEADLYSIGNAL
    =================================================================
    ==8628==ERROR: AddressSanitizer: SEGV on unknown address 0x000000000000
    ==8628==The signal is caused by a WRITE memory access.
    ==8628==Hint: address points to the zero page.
        #0 0x5640db21937b in string_fill string_fill.c:8
        #1 0x5640db219798 in test_string_fill_null test_string_fill.c:33

### string_concat

**NOTE**: You may use functions from the `ctype.h` header, but not from the `string.h` header.

For this part, you will work on a function that concatenates two strings.
Concatenation means there are two strings, and the second string is added to the
back of the first string. For example: "AAA" and "BBB" concatenated becomes
"AAABBB".

You will be given a char array that contains a string (and some additional empty
space). This is called `src1` for destination. You are also provided the total
capacity for the array, called `src1_cap`. Note that `src1` is already *partially
filled*, so you need to first find the end of that partial data.

You will also be given a string that will be concatenated to the first string.

The function looks like this. You are passed two strings, `src1` and `src2`.
`src1` contains a string, but *also* has additional space after that. The total
capacity of `src1` is therefore in `src1_cap`.

    void string_concat(char *src1, int src1_cap, const char* src2);

> [!NOTE]
> Because strings are char arrays in C, you *cannot* just do `a + b`.

Some test cases (assuming `src1_cap` is 4):

| src1  | src2 | new src1 (result) |
| ----- | ---- | ----------------- |
| "A"   |  "B" |         "AB"      |
| "AA"  |  "B" |        "AAB"      |
| "AA"  | "BB" |        "AAB"      |

Last example is because `src1` has capacity of 4, but because we need the terminator, we can only
hold up to 3 characters.

### array_create_evens

**NOTE**: You should have completed the "Memory Management" lecture before attempting this part.

For this part, you will implement a function that *creates* an array with even numbers, from `begin`
to `end`, in increasing order. The function definition looks like the following:

    int* array_create_evens(int begin, int end);

To create an array, you need to call `malloc` to allocate a dynamic array, then
fill in the array. Lastly, return this pointer (the testing fraweork is
responsible for freeing this array, so no worries).

If the range is impossible (for example, 3 and 3), then don't call malloc and simply return `NULL`.

Some test cases:

| begin | end | returns |
| ----- | --- | ------- |
|   1   |  4  |   {2,4} |
|   1   |  5  |   {2,4} |
|   3   |  3  |   NULL  |
|   5   |  1  |   NULL  |


> [!NOTE]
> If you get the following error, this means the array *you created* wasn't
> large enough so the tests went out-of-bounds. Make sure you call malloc with
> `sizeof(int) * length`

    =================================================================
    ==9129==ERROR: AddressSanitizer: heap-buffer-overflow
        #0 0x55827f7cc954 in UnityAssertEqualIntArray unity.c:853
        #1 0x55827f7ca4ad in test_array_create_11_12 test_array_create.c:24

### capitalize

**NOTE**: You should have completed the "Memory Management" lecture before attempting this part.

For this part, you will implement a function that takes a string `s` and returns a *new* string that
has all of its lower-case alphabet letters into uppercase, using the `toupper` function. All
other letters should be left alone.

The function definition looks like the following:

    char* capitalize(const char *s);

Note that the function returns a pointer to an character array, so you need to use dynamic memory (aka `malloc`) here to
first create the array before filling it in with uppercase letters, then returning it. I will bre
responsible for freeing the memory, so don't worry!

Also, **make sure** you fully understand the difference between a character array, and a
null-terminated string. What is the length of an array `{'a', 'b', 'c'}`, vs. the length of a string
``abc``? If the size isn't big enough, you may get a buffer overflow like the previous function.
