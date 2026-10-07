CFLAGS += -Wall -Wextra -Wfatal-errors -g3
CFLAGS += -Werror=vla -Werror=shadow -Wno-unused -Wno-unused-parameter
CFLAGS += -fsanitize=address -fsanitize=undefined

all: test_head test_tail test_size test_find test_toarray test_create_destroy test_create_append test_fromarray test_remove

test_head: unity.c list.c test_head.c
	$(CC) $(CFLAGS) -o test_head unity.c list.c test_head.c

test_tail: unity.c list.c test_tail.c
	$(CC) $(CFLAGS) -o test_tail unity.c list.c test_tail.c

test_size: unity.c list.c test_size.c
	$(CC) $(CFLAGS) -o test_size unity.c list.c test_size.c

test_find: unity.c list.c test_find.c
	$(CC) $(CFLAGS) -o test_find unity.c list.c test_find.c

test_toarray: unity.c list.c test_toarray.c
	$(CC) $(CFLAGS) -o test_toarray unity.c list.c test_toarray.c

test_create_destroy: unity.c list.c test_create_destroy.c
	$(CC) $(CFLAGS) -o test_create_destroy unity.c list.c test_create_destroy.c

test_create_append: unity.c list.c test_create_append.c
	$(CC) $(CFLAGS) -o test_create_append unity.c list.c test_create_append.c

test_fromarray: unity.c list.c test_fromarray.c
	$(CC) $(CFLAGS) -o test_fromarray unity.c list.c test_fromarray.c

test_remove: unity.c list.c test_remove.c
	$(CC) $(CFLAGS) -o test_remove unity.c list.c test_remove.c

.PHONY: clean
clean:
	rm -rf test_head test_tail test_size test_find test_toarray test_create_destroy test_create_append test_fromarray test_remove
