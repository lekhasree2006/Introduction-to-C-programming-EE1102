#include <stdio.h>
int strlength(char *str);
#define max_len 1000
int getlinee(char *,int,FILE *);
int main()
{
   //char *fn;
   char filename[max_len];
   FILE *iop;
   char *line;
   int line_len;
   int max;
   //fn = filename;
   printf("Enter file name to be read:");
   scanf("%s",filename);   //reading file name from user
   iop = fopen(filename,"r");
   printf("Enter max length of line to be read:");   //input max length to be read
   scanf("%d",&max);
   line_len = getlinee(line,max,iop);
   fclose(iop);
   printf("%d\n",line_len);
   return 0;
}

int getlinee(char *line, int max, FILE *iop)
{
   int n;
   fgets(line,max,iop);
   char *p;
   p = line;
   while(*p != '\n')
   p++;
   *p = '\0';
   puts(line);
   n = strlength(line);
   return n;
}
   
int strlength(char *str)
{
   int n;
   char *ptr;
   ptr = str;
   while (*ptr != '\0')
   ptr++;
   n = ((ptr - str)/sizeof(char));  
   return n;
} 

