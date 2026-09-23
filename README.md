# Assignment 1

## Introduction

In this assignment, you will be writing functions that use basic concepts from the C programming
language.

To get started, first clone from GitHub.

### Build Instructions

To build this project run the `make` command in the terminal. You must run this *every time you change a file*.

### Running Unit Tests

To run the unit tests, run the following command for `test_price` (change for each function):

    ./test_price

### Commit Instructions

After completing each function, first add the file to staging, for example:

    git add price.c

Then do the actual commit:

    git commit -m 'Completed price'

You should commit at least once after each function.

When you are ready to submit the assignment, run the following command:

    git push

## Instructions

### price

You are to write a function that computes the price of `count` items, each item being `peritem` in
dollars (we don't do cents!). However, if you buy in bulk, every additional item over the limit is
half price. For example, is `bulk_limit` is 10 and you buy 25 items, 10 items are regular price and
15 items are half price. If any are negative, return 0.

Some test cases:

| peritem | count | bulk_limit | return |
| ------- | ----- | ---------- | ------ |
|     2   |   3   |     10     |    6   |
|     2   |   12  |     10     |   22   |
|     2   |   -1  |     10     |    0   |

Second line is 22 because 10 items at full price ($2) and 2 items at half price ($1).

### power

You are to write a function that computes `x` to the power of `y`. Do *not* use the `pow` function;
instead use a loop (`for` or `while`) to compute this. If either `x` or `y` is negative, return 0.
For any non-negative `x` and `y=0`, return 1.

Some test cases:

|  x |  y | return |
| -- | -- | ------ |
|  2 |  1 |   2    |
|  2 |  3 |   8    |
|  2 |  0 |   1    |
|  2 | -1 |   0    |
| -2 |  1 |   0    |

### add_all_pos

You are given an array and the corresponding length, and add all positive numbers in the array. If
array is empty, the it points to nothing (`NULL`). In this case, you must return 0.

|   array  | return |
| -------- | ------ |
|  NULL    |    0   |
|  {11}    |   11   |
| {11,12}  |   23   |
| {11,-12} |   11   |
| {-11,-12}|    0   |

### max_diff

You are given an array and the corresponding length. Compute the largest difference between the
values (in other words, the difference between the max and min values). Like `add_all_pos`, you must
check for `NULL` and return 0.

|   array     | return |
| ----------- | ------ |
|  NULL       |    0   |
|  {11}       |    0   |
| {11,12}     |    1   |
| {11,21}     |   10   |
| {21,11}     |   10   |
| {11,12,21}  |   10   |
| {11,21,12}  |   10   |
