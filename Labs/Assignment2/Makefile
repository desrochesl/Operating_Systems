CFLAGS += -Wall -Wextra -Wfatal-errors -g3
CFLAGS += -Werror=vla -Werror=shadow -Wno-unused -Wno-unused-parameter
CFLAGS += -fsanitize=address -fsanitize=undefined

all: test_array_fill test_valid_password test_string_fill test_string_concat test_array_create test_capitalize

test_array_fill: unity.c array_fill.c test_array_fill.c
	$(CC) $(CFLAGS) -o test_array_fill unity.c array_fill.c test_array_fill.c

test_valid_password: unity.c valid_password.c test_valid_password.c
	$(CC) $(CFLAGS) -o test_valid_password unity.c valid_password.c test_valid_password.c

test_string_fill: unity.c string_fill.c test_string_fill.c
	$(CC) $(CFLAGS) -o test_string_fill unity.c string_fill.c test_string_fill.c

test_string_concat: unity.c string_concat.c test_string_concat.c
	$(CC) $(CFLAGS) -o test_string_concat unity.c string_concat.c test_string_concat.c

test_array_create: unity.c array_create.c test_array_create.c
	$(CC) $(CFLAGS) -o test_array_create unity.c array_create.c test_array_create.c

test_capitalize: unity.c capitalize.c test_capitalize.c
	$(CC) $(CFLAGS) -o test_capitalize unity.c capitalize.c test_capitalize.c

.PHONY: clean
clean:
	rm -rf test_array_fill test_valid_password test_string_fill test_string_concat test_array_create test_capitalize

