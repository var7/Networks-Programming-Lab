//server
#include <rpc/rpc.h> /* standard RPC include file */
#include <fcntl.h>
#include <string.h>
#include "file.h"
/* this file is generated by rpcgen */
#define MAX 20000
char** get_file_1_svc(char ** argp, struct svc_req *rqstp)
{
    static char *buff; /* must be static */
    char *tmp, n;
    int fd;
    fd = open(*argp, O_RDONLY);
    if (fd < 0)
    {
        perror("file open"); exit(0);
    }
    buff = (char *) malloc(MAX);
    tmp = (char *) malloc(MAX);
    while (read(fd, tmp, MAX) > 0)
    {
        strcat(buff, tmp);
    }
    close(fd);
    return (&buff);
}
