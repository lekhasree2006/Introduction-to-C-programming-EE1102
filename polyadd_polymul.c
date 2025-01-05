/* Addition and multiplication of two linear polynomials*/
/*Code*/

#include <stdio.h>
int main()
{
  int a,b,c,d,e,f,g,h,i;
  printf("Enter two linear polynomial functions of the form ax+b:\n");
  scanf("%dx+%d %dx+%d",&a,&b,&c,&d);
  e = a*c;
  f = a*d + b*c;
  g = b*d;
  h = a + c;
  i = b + d;
  printf("The sum of %dx+%d and %dx+%d is %dx+%d \n",a,b,c,d,h,i);
  printf("The product of %dx+%d and %dx+%d is %dx^2+%dx+%d\n",a,b,c,d,e,f,g);
  return 0;
  
}

/*Output*/
/*Enter two linear polynomial functions of the form ax+b:
3x+2 4x+5
The sum of 3x+2 and 4x+5 is 7x+7The product of 3x+2 and 4x+5 is 12x^2+23x+10lekhasree@Lekhaubuntu:~/Documents$ ./poly
Enter two linear polynomial functions of the form ax+b:
2x+9 5x+12
*/
  

