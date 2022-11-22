//
// Created by Amit on 20/11/2022.
//

#include <stdio.h>
#include <stdlib.h> // For exit()
#include <sys/stat.h>
#include <fcntl.h>
#include<limits.h>
#include <errno.h>
// #include<string.h>
// #include <unistd.h>
#define BUF_SIZE 8192



/**
 * How to run the file->
 * 1.Compile (Using makefile)
 * 2. /.copy <copy_from_destination> <copy_to_destination>
 */


int copyToFile(int fd_src, int fd_dest)
{
    ssize_t in, out;
    char buf[BUF_SIZE];
        while (1) {
            in = read(fd_src, buf, BUF_SIZE);
            if (in <= 0) break;
            out = write(fd_dest, buf, in);
            if (out <= 0) break;
        }
    printf("file is copied/n");

    return 0;
}


int main(int argc, char **argv)
{
    if (argc != 3 && argc !=4 )
    {
        printf("Usage : copy <file1> <file2>");
        exit(1);

    }
    char* from = argv[1];
    char* to = argv[2];
    int fd_src, fd_dest;

    if ((fd_src = open(from ,O_RDONLY)) < 0)
    {
        perror("Error when opening the from file!");
        exit(1);
    }
    if ((fd_dest = open(to ,O_RDONLY | O_WRONLY | O_TRUNC | O_WRONLY|O_CREAT , 0666)) < 0)
    {
        perror("Error when opening the to file!");
        exit(1);
    }

    if (argc == 3) // Three arguments -> regular copy
    {
        copyToFile(fd_src, fd_dest);
        return 0;
    }

    struct stat buffer;
    int status;

    status = lstat(from, &buffer);
    if (status == -1)
    {
        copyToFile(fd_src, fd_dest);
        return 0;
    }

    char linkBuffer[PATH_MAX];
    ssize_t nbytes = readlink(argv[1], linkBuffer, sizeof(linkBuffer));
    if (nbytes == -1) {
        copyToFile(fd_src, fd_dest);
        return 0;
    }
    ssize_t writtenBytes;
    writtenBytes = write(fd_dest, linkBuffer, nbytes);
    if (writtenBytes < 0)
        {
            printf("this is the error\n");
            if (errno == EDQUOT)
            {
                printf("ERROR: out of quota.\n");
            }
            else if (errno == ENOSPC)
            {
                printf("ERROR: not enough disk space.\n");
            }
        }

    else printf("file is copied/n");

    close(fd_src); 
    close(fd_dest);


    return 0;
}