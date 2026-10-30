#!/usr/bin/env bats

bats_load_library bats-support
bats_load_library bats-assert

# Run Once at the start
function setup_file(){
    PATH="$(pwd):$PATH"
}

@test "parta_main" {
    run parta_main

    cat << EOF | assert_output -   # Assert if output matches
ERROR: Missing arguments
EOF
    assert [ "$status" -eq 1 ]                             # Assert if exit status matches
}
@test "parta_main fcfs" {
    run parta_main fcfs

    cat << EOF | assert_output -   # Assert if output matches
ERROR: Missing arguments
EOF
    assert [ "$status" -eq 1 ]                             # Assert if exit status matches
}
@test "parta_main rr" {
    run parta_main rr

    cat << EOF | assert_output -   # Assert if output matches
ERROR: Missing arguments
EOF
    assert [ "$status" -eq 1 ]                             # Assert if exit status matches
}
@test "parta_main rr 2" {
    run parta_main rr 2

    cat << EOF | assert_output -   # Assert if output matches
ERROR: Missing arguments
EOF
    assert [ "$status" -eq 1 ]                             # Assert if exit status matches
}

@test "parta_main fcfs 5" {
    run parta_main fcfs 5

    cat << EOF | assert_output -   # Assert if output matches
Using FCFS

Accepted P0: Burst 5
Average wait time: 0.00
EOF
    assert [ "$status" -eq 0 ]                             # Assert if exit status matches
}
@test "parta_main rr 2 5" {
    run parta_main rr 2 5

    cat << EOF | assert_output -   # Assert if output matches
Using RR(2)

Accepted P0: Burst 5
Average wait time: 0.00
EOF
    assert [ "$status" -eq 0 ]                             # Assert if exit status matches
}

@test "parta_main fcfs 5 8 2" {
    run parta_main fcfs 5 8 2

    cat << EOF | assert_output -   # Assert if output matches
Using FCFS

Accepted P0: Burst 5
Accepted P1: Burst 8
Accepted P2: Burst 2
Average wait time: 6.00
EOF
    assert [ "$status" -eq 0 ]                             # Assert if exit status matches
}

@test "parta_main rr 2 5 8 2" {
    run parta_main rr 2 5 8 2

    cat << EOF | assert_output -   # Assert if output matches
Using RR(2)

Accepted P0: Burst 5
Accepted P1: Burst 8
Accepted P2: Burst 2
Average wait time: 5.67
EOF
    assert [ "$status" -eq 0 ]                             # Assert if exit status matches
}

