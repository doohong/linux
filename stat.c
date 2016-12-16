#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

char* TimetoString(struct tm *t);

int main(int argc, char *argv[]){

   struct stat s;

   if(argc != 2){
      fprintf(stderr,"%s file name\n",argv[0]);
      exit(0);
   }

   stat(argv[1], &s); 

   printf("File : \'%s\'\n",argv[1]);
   printf("Size : %d\t Blocks : %d\t IO Block : %d\n",s.st_size,s.st_blocks,s.st_blksize);
   printf("Device : %d\t Inode : %d\t Links : %d\n",s.st_dev,s.st_ino,s.st_nlink);
   printf("Access : %s\n",TimetoString(localtime(&s.st_ctime)));
   printf("Modify : %s\n",TimetoString(localtime(&s.st_mtime)));
   printf("Change : %s\n",TimetoString(localtime(&s.st_atime)));
   
}

char* TimetoString(struct tm *t){
   static char s[20];

   sprintf(s, "%04d-%02d-%02d %02d:%02d:%02d",t->tm_year+1900, t->tm_mon+1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
   return s;
}
   

