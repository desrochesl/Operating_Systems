#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    char *f = "/tmp/p.fifo";
    mkfifo(f, 0666);

    int fd = open(f, O_WRONLY);
    write(fd, "Hello?\n", 6);
    close(fd);
    return 0;
}