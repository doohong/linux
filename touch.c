#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

void main(int argc, char *argv[])
{
  int fd,i;
if(!strcmp(argv[1],"-c"))
exit(1);
else{
for(i=1;i<argc;i++){
fd=open(argv[i],O_RDWR| O_CREAT,0664);
close(fd);}
}
}
