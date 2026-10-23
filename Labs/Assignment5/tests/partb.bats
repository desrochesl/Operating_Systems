#!/usr/bin/env bats

bats_load_library bats-support
bats_load_library bats-assert
bats_load_library bats-file

# Run Once at the start
function setup_file(){
    PATH="$(pwd):$PATH"
}

@test "partb" {
    run partb

    assert_output "USAGE: partb FILEIN FILEOUT"             # Assert if output matches
    assert [ "$status" -eq 1 ]                              # Assert if exit status was 1
}
@test "partb tests/file1.txt output.txt" {
    rm -f output.txt
    run partb "tests/file1.txt" "output.txt"

    assert_file_exist output.txt                            # Assert if file was created
    assert_files_equal "output.txt" "tests/partb_file1_output.txt"     # Assert if output.txt matches
}
@test "partb tests/file2.txt output.txt" {
    rm -f output.txt
    run partb "tests/file2.txt" output.txt

    assert_file_exist output.txt                            # Assert if file was created
    assert_files_equal "output.txt" "tests/partb_file2_output.txt"     # Assert if output.txt matches
}

