# Implementing Contiguous Memory Allocation

## Introduction

In this assignment, you will implementing contiguous memory allocation.

### Build Instructions

To build this project run the `make` command in the terminal. You must run this *every time you change a file*.

### Unit Tests

To run the unit tests, run the associated tests for each method, e.g.

    ./test_parta_init_term
    ./test_parta_at

and so on.

### Commit Instructions

After completing Part A, first add the file called `parta.c` to staging:

    git add parta.c

Then do the actual commit:

    git commit -m 'Completed Part A'

Do the same after every function/file completed.

When you are ready to submit the assignment, run the following command:

    git push

## Part A Instructions

In this assignment, you will be writing a memory management system that uses contiguous memory
allocation with *first-fit allocation*.

However, to make things easier, you do not need to write functions that actually provide bytes to
the user (like malloc/free). Instead, you will only write the parts that manage how many bytes are
available, and are owned by whom.

The memory is divided into regions. Some regions may be owned (called a "partition"), some may be
free (called a "hole"). For example, we might have a situation like the following:

     0 +---------+
       | NOBODY  |
       |         |
    10 +---------+
       | X       |
    18 +---------+
       | NOBODY  |
    20 +---------+
       | Y       |
    24 +---------+

There are two partitions (sized 8 and 4), and two holes (sized 10 and 2).

The memory manager will receive either allocate requests by some process (in which you'll need to find a hole and
mark it as owned), or free requests (in which you'll convert a partition into a hole).

The above information is managed by your memory manager by a linked list. Each node looks like the following:

    struct mem_region {
        int size;
        int owner;
        struct mem_region* next;
    };

Size indicates how large the region is.

Owner indicates who the owner process is (and if free, mark as `OWNER_NOBODY`, which is defined as `-1`).
Next indicates the next pointer in the linked list.

For example, the above table can be displayed as follows:

    +--------------+    +------+    +--------------+   +------+
    | 10           |    | 8    |    | 2            |   | 4    |
    | OWNER_NOBODY | -> | X    | -> | OWNER_NOBODY | ->| Y    |
    | next         |    | next |    | next         |   | NULL |
    +--------------+    +------+    +--------------+   +------+

### Init, term, length

The `mem_region_init` function takes a single argument, `size`, which *mallocs* a linked list node
(with size of `size` and owned by `OWNER_NOBODY`).

The `mem_region_term` function takes a single argument, the linked list, and calls free on every one
of them.

The code for this should look almost the same as your linked list assignment.

For example, if you call init with 10, you get the following node malloced.

    +--------------+
    | 10           |
    | OWNER_NOBODY |
    | NULL         |
    +--------------+

Before testing your code, continue at complete the next set of functions (length, at) first.

### Length and At

These helper functions traverse the linked list. `mem_region_length` returns the length of the
linked list, and `mem_region_at` returns the memory region at the specified position.

For example, given the following list:

    +--------------+    +------+    +--------------+   +------+
    | 10           |    | 8    |    | 2            |   | 4    |
    | OWNER_NOBODY | -> | X    | -> | OWNER_NOBODY | ->| Y    |
    | next         |    | next |    | next         |   | NULL |
    +--------------+    +------+    +--------------+   +------+

`mem_region_at(0)` returns the unowned size-10 region, whereas `mem_region_at(3)` returns the last
region (owned by Y).

`mem_region_length` returns 4.

### Assign

The assign function creates a new partition by splitting the current hole and assigning the first
half to the owner. If the hole is too large, then another region should be created after the current
one as a free hole.

For example, let's say we have a single current hole is size 4:

    +--------------+
    | 4            |
    | OWNER_NOBODY |
    | NULL         |
    +--------------+

If ID 10 requests size 4, you get a single partition of size 4.

    +--------------+
    | 4            |
    | Owner = 10   |
    | NULL         |
    +--------------+

If on the other hand, the current hole is size 4 and the owner requests size 1, you get a single partition of size 1, and another
hole of size 3 added after the current one.

    +--------------+    +--------------+
    | 1            |    | 3            |
    | Owner = 10   | -> | OWNER_NOBODY |
    | next         |    | NULL         |
    +--------------+    +--------------+

If the hole is not a hole (i.e. owned by nobody) or is not large enough, do nothing.

### Merge

The merge function scans through all regions (all nodes of the linked list) and merge empty holes into a single larger one.
For example, if there are two holes, one size 4 and another size 6 that is immediately next to each other, resize the
first to size 10 and free the second one.

Thus this:

    +--------------+    +--------------+
    | 4            |    | 6            |
    | OWNER_NOBODY | -> | OWNER_NOBODY |
    | next         |    | NULL         |
    +--------------+    +--------------+

becomes this:

    +--------------+
    | 10           |
    | OWNER_NOBODY |
    | NULL         |
    +--------------+

If the hole is not a hole (i.e. owned by nobody) or is not large enough, do nothing.

### Alloc/Free

Assign/Merge functions are internal functions that isn't very important to users. The important work happens in alloc
and free.

The alloc function takes in three arguments, the list (pointed to by the head node), a potential owner and the size. It
searches all regions and identifies a hole that's large enough, starting from the head (remember, we're using
first-fit!). It then inserts the partition (by calling assign from A.2).

The free function takes in two arguments, the list and a ID. It searches for the partition (owner == ID), marks it as
owned by nobody, and merges all holes that may get created.
