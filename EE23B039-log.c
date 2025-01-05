/*Code*/

#include <stdio.h>
#include <math.h>
int main()
{
   int i;
   float x,y,ln;
   printf("enter any real number between -1 and 1:");
   scanf("%f",&x);
   ln = 0;
   for (i = 1; i <= 10; i++)
   {   y = pow(x,i)/i;
      if (i % 2 != 0)
      {
         printf("(%f * %d)/%d - ",x ,i ,i);
         ln = ln + y;
      }
      else 
       {
         printf("(%f * %d)/%d + ",x ,i ,i);
         ln = ln - y;
       }
   }
   printf("\nln(1 + %f) = %f",x,ln);
   return 0;
}

/*Output*/
/*
lekhasree@Lekhaubuntu:~/Documents$ gcc EE23B039-log.c -lm
lekhasree@Lekhaubuntu:~/Documents$ ./a.out
enter any real number between -1 and 1:0.5
(0.500000 * 1)/1 - (0.500000 * 2)/2 + (0.500000 * 3)/3 - (0.500000 * 4)/4 + (0.500000 * 5)/5 - (0.500000 * 6)/6 + (0.500000 * 7)/7 - (0.500000 * 8)/8 + (0.500000 * 9)/9 - (0.500000 * 10)/10 + 
ln(1 + 0.500000) = 0.405435
*/


