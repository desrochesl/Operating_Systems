CFLAGS += -Wall -Wextra -Wfatal-errors -g3
CFLAGS += -Werror=vla -Werror=shadow -Wno-unused -Wno-unused-parameter
CFLAGS += -fsanitize=address -fsanitize=undefined

all: test_parta_init_term test_parta_at test_parta_assign test_parta_merge test_parta_alloc test_parta_alloc_free

test_parta_init_term: parta.c unity.c test_parta_init_term.c
	$(CC) $(CFLAGS) -o test_parta_init_term parta.c unity.c test_parta_init_term.c

test_parta_at: parta.c unity.c test_parta_at.c
	$(CC) $(CFLAGS) -o test_parta_at parta.c unity.c test_parta_at.c

test_parta_assign: parta.c unity.c test_parta_assign.c
	$(CC) $(CFLAGS) -o test_parta_assign parta.c unity.c test_parta_assign.c

test_parta_merge: parta.c unity.c test_parta_merge.c
	$(CC) $(CFLAGS) -o test_parta_merge parta.c unity.c test_parta_merge.c

test_parta_alloc: parta.c unity.c test_parta_alloc.c
	$(CC) $(CFLAGS) -o test_parta_alloc parta.c unity.c test_parta_alloc.c

test_parta_alloc_free: parta.c unity.c test_parta_alloc_free.c
	$(CC) $(CFLAGS) -o test_parta_alloc_free parta.c unity.c test_parta_alloc_free.c

.PHONY: clean
clean:
	rm -rf test_parta_init_term test_parta_at test_parta_assign test_parta_merge test_parta_alloc test_parta_alloc_free
