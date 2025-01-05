                                                     /*Prime number*/
/*Code*/
#include <stdio.h>
int main()
{
   int n,r,x,i;
   x = 1;
   i = 0;
   printf("Enter an integer:");
   scanf("%d",&n);
   if (n < 0)
     printf("Enter a positive integer!! negative numbers cannot be categorised as prime or composite\n");
   else 
   {
   if (n == 1 || n == 0)
     printf("The entered number is neither prime nor composite.\n");
   else
   {
     while (x <= n)
     {
        r = n % x;
        if (r == 0)
           i++;
        x++;
        
     }
     if (i == 2)
       printf("The entered number is a prime number\n");
     else 
       printf("The entered number is composite number\n");
       
   }
   }
   return 0;
}   
     
/*Output*/
/*
lekhasree@Lekhaubuntu:~/Documents$ gcc EE23B039_prime-number.c
lekhasree@Lekhaubuntu:~/Documents$ ./a.out
Enter an integer:-90
Enter a positive integer!! negative numbers cannot be categorised as prime or composite
lekhasree@Lekhaubuntu:~/Documents$ ./a.out
Enter an integer:34
The entered number is composite number
lekhasree@Lekhaubuntu:~/Documents$ ./a.out
Enter an integer:23
The entered number is a prime number
lekhasree@Lekhaubuntu:~/Documents$ ./a.out
Enter an integer:0
The entered number is neither prime nor composite.
lekhasree@Lekhaubuntu:~/Documents$ 
*/
     
