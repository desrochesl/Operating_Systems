CFLAGS += -Wall -Wextra -Wfatal-errors -g3
CFLAGS += -Werror=vla -Werror=shadow -Wno-unused -Wno-unused-parameter
CFLAGS += -fsanitize=address -fsanitize=undefined

all: test_parta_init test_parta_run_proc test_parta_fcfs test_parta_rr_next test_parta_rr parta_main

test_parta_init: parta.c unity.c test_parta_init.c
	$(CC) $(CFLAGS) -o test_parta_init parta.c unity.c test_parta_init.c

test_parta_run_proc: parta.c unity.c test_parta_run_proc.c
	$(CC) $(CFLAGS) -o test_parta_run_proc parta.c unity.c test_parta_run_proc.c

test_parta_fcfs: parta.c unity.c test_parta_fcfs.c
	$(CC) $(CFLAGS) -o test_parta_fcfs parta.c unity.c test_parta_fcfs.c

test_parta_rr_next: parta.c unity.c test_parta_rr_next.c
	$(CC) $(CFLAGS) -o test_parta_rr_next parta.c unity.c test_parta_rr_next.c

test_parta_rr: parta.c unity.c test_parta_rr.c
	$(CC) $(CFLAGS) -o test_parta_rr parta.c unity.c test_parta_rr.c

parta_main: parta.c parta_main.c
	$(CC) $(CFLAGS) -o parta_main parta.c parta_main.c

.PHONY: clean
clean:
	rm -rf test_parta_init test_parta_run_proc test_parta_fcfs test_parta_rr_next test_parta_rr parta_main
