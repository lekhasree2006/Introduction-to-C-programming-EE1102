/*Polynomial multiplication in two varaibles*/
/*Code*/

#include <stdio.h>
int main()
{
  int m,n,p,q,e,f,g;
  printf("Enter two linear polynomial functions of the form ma+nb:\n");
  scanf("%da+%db %da+%db",&m,&n,&p,&q);
  e = m*p;
  f = m*q + n*p;
  g = n*q;
  printf("The product of %da+%db and %da+%db is %da^2+%dab+%db^2\n",m,n,p,q,e,f,g);
  return 0;
  
}

/*Output*/
/*Enter two linear polynomial functions of the form ma+nb:
2a+3b 5a+7b
The product of 2a+3b and 5a+7b is 10a^2+29ab+21b^2
*/
