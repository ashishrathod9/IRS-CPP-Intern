#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char buffer[100];

    // open() system call
    fd = open("test.txt", O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    // read() system call
    ssize_t bytes = read(fd, buffer, sizeof(buffer));
    printf("Read %ld bytes\n", bytes);

    // write() system call
    write(1, buffer, bytes);  // 1 is stdout

    // close() system call
    close(fd);

    return 0;
}
