                                                     /* Sum of Series */
/*Code*/

#include <stdio.h>
#include <math.h>
int main()
{
   int i,l,j,k,n,number;
   float y,x,sum_even,sum_odd,sume,sumo;
   printf("Enter an integer:");
   scanf("%d",&number);
   sume = 1;
   sumo = 1;
   sum_even = 1;
   sum_odd = 1;
   printf("----------------------------------------\n");
   printf("N \t even sum \t odd sum\n");
   printf("----------------------------------------\n");
   for ( n = 2; n <= number; n = n + 2)
   {
     for (i = 1,sume = 1; i < n; i++)
    {
      x = ((float)i) /((float) (i + 1));
      y = pow(-1,i) * x;
      sume = sume + y;
    }  
   
     for (j = 1, sumo = 1; j < n-1; j++)
    {
      x = ((float)j) /((float) (j + 1));
      y = pow(-1,j) * x;
      sumo = sumo + y;
    }  
    printf("%d \t %f \t %f\n",n,sume,sumo);
   }
   printf("----------------------------------------\n");
   printf("N \t even sum \t odd sum\n");
   printf("----------------------------------------\n");
   for ( n = 3; n <= number; n = n + 2)
   {
     for (k = 1, sum_odd = 1; k < n; k++)
    {
      x = ((float)k) /((float) (k + 1));
      y = pow(-1,k) * x;
      sum_odd = sum_odd + y;
    }  
   
     for (l = 1, sum_even = 1; l < n-1; l++)
    {
      x = ((float)l) /((float) (l + 1));
      y = pow(-1,l) * x;
      sum_even = sum_even + y;
    }
    printf("%d \t %f \t %f\n",n,sum_even,sum_odd);  
   }
   
   return 0;
}
   
   
/*Output*/
/*lekhasree@Lekhaubuntu:~/Documents$ gcc EE23B039_sum_of_series.c -lm
lekhasree@Lekhaubuntu:~/Documents$ ./a.out
Enter an integer:21
----------------------------------------
N 	 even sum 	 odd sum
----------------------------------------
2 	 0.500000 	 1.000000
4 	 0.416667 	 1.166667
6 	 0.383333 	 1.216667
8 	 0.365476 	 1.240476
10 	 0.354365 	 1.254365
12 	 0.346789 	 1.263456
14 	 0.341295 	 1.269866
16 	 0.337128 	 1.274628
18 	 0.333860 	 1.278305
20 	 0.331229 	 1.281229
----------------------------------------
N 	 even sum 	 odd sum
----------------------------------------
3 	 0.500000 	 1.166667
5 	 0.416667 	 1.216667
7 	 0.383333 	 1.240476
9 	 0.365476 	 1.254365
11 	 0.354365 	 1.263456
13 	 0.346789 	 1.269866
15 	 0.341295 	 1.274628
17 	 0.337128 	 1.278305
19 	 0.333860 	 1.281229
21 	 0.331229 	 1.283610
lekhasree@Lekhaubuntu:~/Documents$ 

*/

