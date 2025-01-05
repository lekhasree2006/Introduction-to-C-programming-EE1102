//Code

#include <stdio.h>
#include <stdlib.h>
float *mat1[4];       //declaring arrays of pointers for each row for both the input matrices and the product matrix
float *mat2[5];
float *mat3[4];
float rowmat1[5];
float rowmat2[3];
float rowmat3[3];
float *p;             //dummy pointers used later in the following program
float *q;
float sum;
int main()
{
   int i,j,k,l;
   j = 0;
   k = 0;
   float **mat1 = (float **)malloc(sizeof(float *) * 4);  //allocate memory for each pointer array used
   for(i=0; i<4;i++)
    {
        mat1[i]=(float*)malloc(5*sizeof(float));        //allocate memory for each pointer in the pointer array
    }
   float **mat2 = (float **)malloc(sizeof(float *) * 5);
   for(i=0; i<5;i++)
    {
        mat2[i]=(float*)malloc(3*sizeof(float));   
    }
   float **mat3 = (float **)malloc(sizeof(float *) * 4);
   for(i=0; i<4;i++)
    {
        mat3[i]=(float*)malloc(3*sizeof(float));   
    }
   printf("Enter a 4 by 5 matrix:\n");
   do
   {
     p = (float *)malloc(sizeof(float) * 5);        //input of first matrix
     for ( i = 0; i < 5; i++)
     {
        scanf("%f",&rowmat1[i]);
     }
     p = rowmat1;
     mat1[j] = p;         
     j++;
   }
   while (rowmat1[0] != '\n' && j < 4);
   
   printf("Enter a 5 by 3 matrix:\n");
   do
   {
     p = (float *)malloc(sizeof(float) * 3);       //input of second matrix
     for ( i = 0; i < 3; i++)
     {
        scanf("%f",&rowmat2[i]);
     }
     p = rowmat2;
     mat2[k] = p; 
     k++;
   }
   while (rowmat2[0] != '\n' && k < 5);
   
 
   for(l = 0; l < 4; l++)
   {
   	q = (float *)malloc(sizeof(float) * 5);     //dummy variable to store mat1's initial address
   	q = mat1[l];
   	for(i = 0; i < 3; i++)
   	{
     		 sum = 0;
    		 p = (float *)malloc(sizeof(float) * 6);  
    		 for (k = 0; k < 5; k++)
    		 {
      			 sum = sum + (*mat1[l]) * (*(mat2[k]+i));  //loop to do matrix multiplication
      			 mat1[l]++;                                //first multiply and then add the sum to the previous sum
      			
    		 } 
    		 mat1[l] = q;                             //moving pointer mat1 to its initial position
    	 	 rowmat3[i] = sum;                        //assigning sum to an array
    	 	 
    	 	 
  	}
   
  	 p = rowmat3;                             //copying sum to a pointer and putting it in the final multiplication matrix
  	 mat3[l] = p;
   }
   
   
   for(l = 0; l < 4; l++)
   {
      for (k = 0; k < 3; k++)
      {
        printf("%f",*mat3[l]);
        mat3[l]++;                               //printing the multiplication matrix
        printf("  ");
      }
      printf("\n");
   }
   return 0;
}
   
//Output
/*
lekhasree@Lekhaubuntu:~/Documents$ gcc EE23B039_MatMul.c
lekhasree@Lekhaubuntu:~/Documents$ ./a.out
Enter a 4 by 5 matrix:
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
Enter a 5 by 3 matrix:
1 2 3
1 2 3
1 2 3
1 2 3
1 2 3
15.000000  30.000000  45.000000  
15.000000  30.000000  45.000000  
15.000000  30.000000  45.000000  
15.000000  30.000000  45.000000  

*/   
