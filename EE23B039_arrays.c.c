//Code

#include <stdio.h>
#include <string.h>
int main()
{
	FILE* fp = fopen("empldata.csv", "r");
	char buffer[1024];
	int row = 0;
        int column = 0;
        int i,p1=0;
        int j;
        char id[1000][5], status[1000][10], name[1000][10], jobtitle[1000][15];
        char rating[1000][10], projects[1000][10], whours[1000][10], people[1000][10];
        
 	//Copying data into arrays
	while (fgets(buffer,1024, fp)) 
        {
        	column = 0;
        	char* value = strtok(buffer, ", ");
        	while (value)
        	{
        	if (column == 0)
        	{
        		strcpy(id[row], value);
        	}
        	if (column == 1)
        	{
        		strcpy(status[row], value);
        	}
        	if (column == 2)
        	{
        		strcpy(name[row], value);
        	}
        	if (column == 3)
        	{
        		strcpy(jobtitle[row], value);
        	}
        	if (column == 4)
        	{
        		strcpy(rating[row], value);
        	}
        	if (column == 5)
        	{
        		strcpy(projects[row], value);
        	}
        	if (column == 6)
        	{
        		strcpy(people[row], value);
        	}
        	if (column == 7)
        	{
        		strcpy(whours[row], value);
        	}
        	
        	
        	column++;
        	value = strtok(NULL, ", ");
        	}
        	row++;
        }
        // checking if there are any inactive members and if any, setting all their data to null and status as inactive
        for(i = 0; i < row; i++)
       {
       		if (strcmp(status[i],"inactive") == 0)
       		{
       			
       			for(j = 0; j < row; j++)
       			{
       				if(atoi(id[j]) == atoi(id[i]))
       				{
       					strcpy(status[j],"inactive");
       					strcpy(jobtitle[j],"\0");
       					strcpy(rating[j],"\0");
       					strcpy(projects[j],"\0");
       					strcpy(people[j],"\0");
       					strcpy(whours[j],"\0");
       				}
       			}
       		}
       	}	
       // number of people working in project 1 and total manhrs spents in project 2
       printf("Question 1:\n");
       for(i = 0; i < row; i++)
       {
       		if ((projects[i][0]) == '1')
       		p1++;
       }
       printf("number of people working in project 1 is %d\n",p1);
       int manhrs = 0;
       for(i = 0; i < row; i++)
       {
       		if ((projects[i][0]) == '2')
       		{
       			manhrs = manhrs + atoi(whours[i]);
       		}
       	}
       	printf("Total manhrs of project 2 is %d\n\n",manhrs);
       	//who reports to manager 
       	printf("Question 2:\n");
       	int empid,manid;
       	for(i = 0; i < row; i++)
       	{
       		if(strcmp(jobtitle[i],"manager") == 0 && atoi(id[i]) != manid)
       		{
       			printf("manager:%s\n", name[i]);
       			manid = atoi(id[i]);
       			for(j = 0; j < row; j++)
       			{
       				if ( atoi(people[j]) == manid && atoi(id[j]) != empid)
       				{
       					printf("%s\n", name[j]);
       					empid = atoi(id[j]);
       				}
       			}
       		}
       	}
       	printf("\n");
       	//who is who's boss
       	printf("Question 3:\n");
        int k = 0;
       	printf("\n");
       	for(i = 0; i < row; i++)
       	{
       		if (atoi(people[i]) != 0)
       		{
       			manid = atoi(people[i]);
       			for (j = 0; j < row; j++)
       			{
       				if(atoi(id[j]) == manid && strcmp(id[j],id[j-1]) != 0 && strcmp(status[j],"active") == 0)
       				{
       					printf("%s is %s's boss in project %s\n",name[j],name[i],projects[i]);
       				}
       			}
       		}
       		
       	}
       	printf("\n");
       	
       	// how many programmers are there i project 1:
       	printf("Question 4:\n");
       	int programmers1 = 0;
       	for(i = 0; i < row; i++)
       	{
       		if(strcmp(jobtitle[i],"programmer") == 0 && atoi(projects[i]) == 1)
       		programmers1 += 1;
       	}
       	printf("No. of programmers working in project 1: %d \n",programmers1);
       	printf("\n");
       	// secretary not reporting to anyone
       	printf("Question 5:\n");
       	for(i = 0; i < row; i++)
       	{
       		if(strcmp(jobtitle[i],"secretary") == 0)
       		{
       			for(j = 0; j < row; j++)
       			{
       				if(strcmp(people[i],id[j]) == 0 && strcmp(status[j],"inactive") == 0 && atoi(id[j]) != empid)
       				{
       					printf("%s doesnot report to anyone\n",name[i]);
       					empid = atoi(id[j]);
       				}
       			}
       		}
       	}
       	printf("\n");
        //person who has no one reporting to him
        printf("Question 6:\n");
       	int num;
       	for(i = 0; i < row; i++)
       	{
       		num = 0;
       		for(j = 0; j < row; j++)
       		{
       			if(strcmp(id[i],people[j]) == 0)
       			num++;
       		}
       		if(num == 0 && i != 0 && (strcmp(id[i],id[i-1]) != 0))
       		printf("%s has no one reporting to him\n",name[i]);
       		
       	}	
       			
        return 0;
}


//Output
/*
Question 1:
number of people working in project 1 is 4
Total manhrs of project 2 is 45

Question 2:
manager:anjali
ganesh

Question 3:

ganesh is hariharan's boss in project 1
ganesh is hariharan's boss in project 2
anjali is ganesh's boss in project 1
anjali is ganesh's boss in project 2
anjali is ganesh's boss in project 3

Question 4:
No. of programmers working in project 1: 1 

Question 5:
tarun doesnot report to anyone

Question 6:
hariharan has no one reporting to him
tarun has no one reporting to him
 has no one reporting to him
lekhasree@Lekhaubuntu:~/Documents$ 
*/
