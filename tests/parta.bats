#!/usr/bin/env bats

bats_load_library bats-support
bats_load_library bats-assert

# Run Once at the start
function setup_file(){
    PATH="$(pwd):$PATH"
}

@test "./parta Hello" {
    run parta Hello

    assert_output HELLO
    assert [ "$status" -eq 0 ]                             # Assert if exit status isn't 0
}

@test "./parta HowDY" {
    run parta HowDY

    assert_output HOWDY
    assert [ "$status" -eq 0 ]                             # Assert if exit status isn't 0
}
@test "./parta Goodbye" {
    run parta Goodbye

    assert_output GOODBYE
    assert [ "$status" -eq 0 ]                             # Assert if exit status isn't 0
}
@test "./parta Hello Goodbye" {
    run parta Hello,Goodbye

    assert_output HELLO,GOODBYE
    assert [ "$status" -eq 0 ]                             # Assert if exit status isn't 0
}
@test "./parta a b c d e f" {
    run parta A B C D E F

    assert_output A,B,C,D,E,F
    assert [ "$status" -eq 0 ]                             # Assert if exit status isn't 0
}
@test "./parta" {
    run parta

    assert_output "ERROR: No arguments"
    assert [ "$status" -eq 1 ]                             # Assert if exit status isn't 1
}
