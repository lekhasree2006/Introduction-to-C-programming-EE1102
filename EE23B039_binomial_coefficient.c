                                                 /*Binomial Coefficient*/
/*Code*/
#include <stdio.h>
int main()
{
   int N,K,i,j;
   unsigned long long int n,k,bi_coeff;
   n = 1; 
   k = 1;
   printf("Enter values of N and K to compute the binomial coefficient N choose K:");
   scanf("%d %d", &N, &K);
   if (N < K)
      printf("enter valid values of N and K (N < K is not possible)");
   else 
      if ((N - K) >= K)
      {
         for (i=N; i > (N - K); i--)
            n = n * i;
         printf("%llu\n",n);
         for (j=1; j <= K; j++)
            k = k * j;
         printf("%llu\n",k);
         bi_coeff = n / k ;
         printf("Binomial coeff=%llu",bi_coeff);
      }
      
      else
      {
         for (i=N; i > K; i--)
            n = n * i;
         for (j=1; j <= (N - K); j++)
            k = k * j;
         bi_coeff = n / k ;
         printf("Binomial coeff=%llu",bi_coeff);
      }
      
   return 0;
   
}
      
/*Output*/
/*
lekhasree@Lekhaubuntu:~/Documents$ gcc EE23B039_binomial_coefficient.c
lekhasree@Lekhaubuntu:~/Documents$ ./a.out
Enter values of N and K to compute the binomial coefficient N choose K:100 98
Binomial coeff=4950lekhasree@Lekhaubuntu:~/Documents$ 
*/
            
           
      
      
      
      
      
      
      
      
      
      
      
      
      
      

