#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>

int main (int argc, char **argv){
    int z;  
    int s[2];


    //create local pair of sockets:

    z = socketpair(AF_LOCAL, SOCK_STREAM,0,s);

    if(z== -1)
    {
        fprintf(stderr,"%s: socketpair(AF_LOCAL, SOCK_STREAM,0)\n", strerror(errno));
        return 1; //Failed
    }

// REport the socket file descriptors returned:s

printf("s[0] = %d;\n",s[0]);
printf("s[1] = %d;\n",s[1]);
system("netstat --unix -p");

return 0;

}