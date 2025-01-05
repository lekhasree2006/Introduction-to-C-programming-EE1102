/*Code*/

#include <stdio.h>
float f(float x);
float trapzd( float (*func) (float x), float a, float b, int n );  //definition of a function to calculate definite integral 
int main()                                                         //through the trapezoidal formula
{
   float a,b,intg;
   int n;
   printf("Enter limits of the integral(lower upper):");
   scanf("%f %f",&a,&b);
   printf("Enter the number of intervals:");
   scanf("%d",&n);
   intg=trapzd(f,a,b,n);
   printf("%f",intg);
   return 0;
}

float f(float x)                           // integrand (here 1/1+x^2)
{
   return 1.0/(1.0+x*x);
}

float trapzd( float (*func) (float x), float a, float b, int n )
{
   float dx,an,bn;
   dx = (b - a)/n;       // dx is the length of each interval
   an = a;               //creating to dummy variables for iteration to happen through the intervals
   bn = a + dx;
   float sum = 0;            //the value of integral is returned as sum so first we declare sum as 0 and then pass it to the loop 
   int i;                    //for each loop it adds 0.5*(func(an) + func(bn))*dx to the sum that is the approximate area bound 
   for (i = 0; i < n+1; i++) //by the and x axis
   {
      sum = sum + 0.5*(func(an) + func(bn))*dx;
      an = bn;
      bn = an + dx;
   }
   return sum;
}

/*Output*/
/*
lekhasree@Lekhaubuntu:~/Documents$ gcc ejfho.c
lekhasree@Lekhaubuntu:~/Documents$ ./a.out
Enter limits of the integral(lower upper):0 1
Enter the number of intervals:1000
0.785900lekhasree@Lekhaubuntu:~/Documents$ ./a.out
Enter limits of the integral(lower upper):0 1
Enter the number of intervals:1000000
0.783443lekhasree@Lekhaubuntu:~/Documents$ ./a.out
Enter limits of the integral(lower upper):0 1
Enter the number of intervals:10000
0.785447lekhasree@Lekhaubuntu:~/Documents$ ./a.out
Enter limits of the integral(lower upper):0 3.14
Enter the number of intervals:1000
1.262773lekhasree@Lekhaubuntu:~/Documents$ 
*/
/*
the output returned matches with the value of integral calculated manually*/
