CFLAGS += -Wall -Wextra -Wfatal-errors -g3
CFLAGS += -Werror=vla -Werror=shadow -Wno-unused -Wno-unused-parameter
CFLAGS += -fsanitize=address -fsanitize=undefined

all: test_add_all_pos test_max_diff test_power test_price

test_add_all_pos: unity.c add_all_pos.c test_add_all_pos.c
	$(CC) $(CFLAGS) -o test_add_all_pos unity.c add_all_pos.c test_add_all_pos.c

test_max_diff: unity.c max_diff.c test_max_diff.c
	$(CC) $(CFLAGS) -o test_max_diff unity.c max_diff.c test_max_diff.c

test_power: unity.c power.c test_power.c
	$(CC) $(CFLAGS) -o test_power unity.c power.c test_power.c

test_price: unity.c price.c test_price.c
	$(CC) $(CFLAGS) -o test_price unity.c price.c test_price.c

.PHONY: clean
clean:
	rm -rf test_add_all_pos test_max_diff test_power test_price

