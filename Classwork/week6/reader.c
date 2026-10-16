#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    char *f = "/tmp/p.fifo";
    mkfifo(f, 0666);

    int fd = open(f, O_RDONLY);
    char buf[64] = {0};
    read(fd, buf, 63);
    printf("got: %s", buf);
    close(fd);
    unlink(f);
    return 0;
}