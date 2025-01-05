//Code  -- Shows warning but no error and gets compiled and output is as expected

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 10    
#define MAXLEN 30
char line[MAXLEN];   
char *lineptr[MAXLINE];      // initializing an array of pointers
int readlines(char *lineptr[],int maxlines);  
void copy_string(char *target, char *source);  //modifying the srtcpy to copy only 30 characters 
int main()
{
   int nlines,i;
   char **lineptr = (char**)malloc(10 * sizeof(char *)); //allocating memory for 2D array
    for(i=0; i<10;i++)
    {
        lineptr[i]=(char*)malloc(30*sizeof(char));    //allocating memory for each string in the array
    }
   nlines = readlines(lineptr,MAXLINE);    //passing pointer array and max number of lines
   
   return 0;
}

int readlines(char *lineptr[],int maxlines)
{
   int j = 0,k,len;
   char *p;
   lineptr[MAXLINE] =malloc(sizeof(char) * MAXLINE);  //allocating new memory for each string in the array so that overwriting will 
                                                      //not happen
   printf("Enter a few strings:");
   do
   {
     p = (char *)malloc(sizeof(char) * MAXLEN); 
     fgets(line,1000,stdin);   //taking the input of entered string randomly put 1000 so that it reads the entire string in one go
     copy_string(p,line);    //copying line array into the pointer p
     lineptr[j] = p;         //assigning p to each element in the pointer array
     j++;
   }while (line[0] != '\n' && j < 10);
   
   
   for( k = 0; k < j; k++)
   printf("%s\n",lineptr[k]);  //print each string in new lines
   
   
   printf("\n");
   return j;
}

void copy_string(char *target, char *source)
{
    int i = 0;
    while (*source != '\0' && i < MAXLEN ) // to restrict only first 30 characters to get copied
    {
        *target = *source;
        source++;
        target++;
        i++;
    }
    *target = '\0';
}

//Output
/*
lekhasree@Lekhaubuntu:~/Documents$ ./a.out
Enter a few strings:Radio signal strikes earth after travelling for eight billion years in space
halleys comet is coming
purpose and significance explained
restict only thirty characters

Radio signal strikes earth aft
halleys comet is coming

purpose and significance expla
restict only thirty characters
*/
/****Shows a few warnings but gets compiled and the required output is obtained*****/


