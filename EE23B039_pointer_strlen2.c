/*Code 2*/
#include <stdio.h>
int strlength(char *);
int main()
{
   int n;
   char arr[1000];
   printf("Enter a string:");
   fgets(arr,1000,stdin);
   n = strlength(arr);
   printf("length of string is:%d",n);
   return 0;
}

int strlength(char *arr)
{
  int n;
  char *ptr;
   ptr = arr;
   while (*ptr != '\0')
   ptr++;
   n = ((ptr - arr)/sizeof(char))-1;  //string length doesnt include '\n' but here that is also included, -1
   return n;
}

/*Output*/
/*
lekhasree@Lekhaubuntu:~/Documents$ gcc EE23B039_pointer_strlen2.c
lekhasree@Lekhaubuntu:~/Documents$ ./a.out
Enter a string:hi hello
length of string is:8lekhasree@Lekhaubuntu:~/Documents$ 
*/
