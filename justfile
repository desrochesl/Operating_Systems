mrun folder name: (make folder name) (run folder name)

make folder name:
    mkdir -p ./bin/{{folder}}
    make -C {{folder}} {{name}}
    mv ./{{folder}}/{{name}} ./bin/{{folder}}/{{name}}

run folder name: 
    ./bin/{{folder}}/{{name}}