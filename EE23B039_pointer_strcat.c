/*Code*/
#include <stdio.h>
#define buffer 1000
void strcatn(char *,char *);
int main()
{
   char *ptr1,*ptr2;
   char arr1[buffer];
   char arr2[buffer];
   ptr1 = arr1;
   ptr2 = arr2;
   printf("Enter the first string:");
   fgets(arr1,buffer,stdin);
   printf("Enter the second string:");
   fgets(arr2,buffer,stdin);
   strcatn(ptr1,ptr2);
   puts(ptr1);
   return 0;
}

void strcatn(char *ptr1, char *ptr2)
{
   while(*ptr1 != '\0' && *ptr1 != '\n')
   ptr1++;
   while(*ptr2 != '\0')
   *ptr1++ = *ptr2++;
   *ptr1 = '\0';
     
}

/*Output*/
/*
lekhasree@Lekhaubuntu:~/Documents$ gcc EE23B039_pointer_strcat.c
lekhasree@Lekhaubuntu:~/Documents$ ./a.out
Enter the first string:hi hello
Enter the second string:this is 
hi hellothis is 

lekhasree@Lekhaubuntu:~/Documents$ 
*/
