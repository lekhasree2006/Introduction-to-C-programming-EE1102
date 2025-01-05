#include <stdio.h>
#include <malloc.h>
#define buffer 100
int strlength(char *);
int main()
{
   int n;
   char *str;
   str = (char *)malloc(sizeof(char)*buffer);
   printf("Enter a string:");
   fgets(str,buffer,stdin);
   printf("\n%s",str); // check if string input or not
   n = strlength(str);
   printf("length of string is:%d",n);
   return 0;
} 

int strlength(char *str)
{
   int n;
   char *ptr;
   ptr = str;
   while (*ptr != '\0')
   ptr++;
   n = ((ptr - str)/sizeof(char))-1;  //string length doesnt include '\n' but here that is also included, -1
   return n;
} 
  
/*Output*/
/*
lekhasree@Lekhaubuntu:~/Documents$ gcc EE23B039_pointer_strlen.c
lekhasree@Lekhaubuntu:~/Documents$ ./a.out
Enter a string:hi hello

hi hello
length of string is:8lekhasree@Lekhaubuntu:~/Documents$ 

*/

