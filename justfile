CC := "gcc"
CFLAGS := "-Wall -Wextra -std=c11"

# Compile and run from bin/
run file: (build file)
    ./.bin/{{ without_extension(file) }}

# Compile to bin/
build file:
    @mkdir -p ".bin/{{ parent_dir(file) }}"
    {{CC}} {{CFLAGS}} {{file}} -o ".bin/{{ without_extension(file) }}"