/* alphabets through for loop */
/*Code*/

#include <stdio.h>
int main()
{
   int i;
   char alphabet;
   for (i = 97; i < 123; i++)
     printf("%c,",i);
   return 0;
} 

/*Execution and Output*/
/*
lekhasree@Lekhaubuntu:~$ cd Documents
lekhasree@Lekhaubuntu:~/Documents$ gcc EE23B039-alph.c
lekhasree@Lekhaubuntu:~/Documents$ ./a.out
a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,lekhasree@Lekhaubuntu:~/Documents$ 
*/

