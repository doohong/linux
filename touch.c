#include <sys/types.h>
#include <utime.h>
#include <sys/time.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>

void main(int argc, char *argv[])
{
  struct stat file_info;
  struct utimbuf act;
  struct utimbuf mod;
  struct utimbuf am;
  time_t timer;
  struct tm t;
  int tstat;

  
  mod.modtime = time(NULL);
 
  int fd,i;
  if(!strcmp(argv[1],"-c"))
  exit(1);
  else if(!strcmp(argv[1],"-a")){
	if(argv[3]==NULL){
		stat(argv[2], &file_info);
		act.actime = time(NULL);
		act.modtime = file_info.st_mtime;
		
		utime(argv[2], &act);
		}
	}
  else if(!strcmp(argv[1],"-m")){
	if(argv[3]==NULL){
		stat(argv[2], &file_info);
		mod.actime = file_info.st_atime;
		mod.modtime = time(NULL);
		
		utime(argv[2], &mod);
		}
	}
   else if(!strcmp(argv[1],"-t")){
         
		strptime(argv[2],"%Y%m%d%H%M",&t);
		t.tm_sec=0;
		timer=mktime(&t);		
		am.actime = timer;
		am.modtime = timer;
		
		utime(argv[3], &am);
		
	}    
  else{
	for(i=1;i<argc;i++){
	fd=open(argv[i],O_RDWR| O_CREAT,0664);
	close(fd);}
      }
}
