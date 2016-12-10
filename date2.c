#include<stdio.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
 void main(int argc, char* argv[])
 {
   int i=2;
   int x;
   long int z;
   time_t timer;
   struct tm *t;
   char week[7][7]={"일", "월", "화", "수", "목", "금", "토"};

	if(argv[1]==NULL)
	{
	   timer = time(NULL);
  	}
	else if(strcmp(argv[1],"-d")==0)
	{
	   while(1)
	   {	
		if(strcmp(argv[i],"yesterday")==0)
	
	    	   timer = time(NULL)-(24*60*60);
		
		else if(strcmp(argv[i],"years")==0)
		{
		   x = atoi(argv[i-1]);
		   if(x!=0)
		   
			z = 24*60*60*365*x;
		   
		   else	
		  
			z = 24*60*60*365;
		   
		   if(strcmp(argv[i+1],"ago")==0)
		   
			timer = time(NULL)-z;
		   
	       	   else
		   
			timer = time(NULL)+z;  
		   
		   
		}
		else if(argv[i]==NULL)
		   break;

		i++;
	   }	
	}				
  t = localtime(&timer);
  printf("%d. %d. %d. (%s) %d:%d:%d\n ", t->tm_year+1900, t->tm_mon+1,t->tm_mday, week[t->tm_wday], t->tm_hour, t->tm_min, t->tm_sec);
 }
