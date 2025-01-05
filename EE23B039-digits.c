/*Code*/

#include <stdio.h>
#include <math.h>
int main()
{
   int n,i,x,y,z,j,t,r;
   printf("enter an integer value: ");
   scanf("%d",&n);
   x = 0;
   for (i = 0; x < n; i++)
      x = pow(10,i);
   z = x / 10;
   
   y = i - 2;  
   t = y;
  
   for (j = 1; j <= y + 1; j++,t--)
   {
      r = ((n % (int)x) - (n % (int)z))/ z;
      printf("%d * 10^%d + ",r,t);
      z = z / 10 ;
      x = x / 10 ;
    }  
   return 0;
}   

/*Output*/
/*
lekhasree@Lekhaubuntu:~/Documents$ gcc EE23B039-digits.c -lm
lekhasree@Lekhaubuntu:~/Documents$ ./a.out
enter an integer value: 26535
2 * 10^4 + 6 * 10^3 + 5 * 10^2 + 3 * 10^1 + 5 * 10^0 + lekhasree@Lekhaubuntu:~/Documents$ 
*/

