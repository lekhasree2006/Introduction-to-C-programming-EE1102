#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STR_LEN 256
typedef struct 
{
        int id;
        char status[10];
        char name[10];
        char jobtitle[15];
        int rating;
        int projects;
        int people;
        int hours;
        
}empdata;
struct member
{
	int id;		
	char *name;	
	struct member *prev;	
	struct member *next;
};

int main()
{
	FILE* fp = fopen("empldata.csv", "r");
	char buffer[1024];
	int row = 0;
	int p1;
        int column = 0;
        int i = 0,j = 0;
        char buf[1024];
        char* tmp;
	empdata info[1000];
	while (fgets(buffer,1024, fp)) 
        {
        	column = 0;
        	char* value = strtok(buffer, ", ");
        	while (value)
        	{
        	if (column == 0)
        	{
        		info[row].id = atoi(value);
        		
        	}
        	if (column == 1)
        	{
        		strcpy(info[row].status, value);
        	}
        	if (column == 2)
        	{
        		strcpy(info[row].name, value);
        	}
        	if (column == 3)
        	{
        		strcpy(info[row].jobtitle, value);
        	}
        	if (column == 4)
        	{
        		info[row].rating = atoi(value);
        	}
        	if (column == 5)
        	{
        		info[row].projects = atoi(value);
        	}
        	if (column == 6)
        	{
        		info[row].people = atoi(value);
        	}
        	if (column == 7)
        	{
        		info[row].hours = atoi(value);
        	}
        	
        	
        	column++;
        	
        	value = strtok(NULL, ", ");
        	
        	}
        	row++;
        }
        // checking if there are any inactive members and if any, setting all their data to null and status as inactive
        for(i = 0; i < row; i++)
       {
       		
       		if (strcmp(info[i].status,"inactive") == 0)
       		{
       			
       			for(j = 0; j < row; j++)
       			{
       				
       				if(info[j].id == info[i].id)
       				{
       					
       					strcpy(info[j].status,"inactive");
       					strcpy(info[j].jobtitle,"\0");
       					info[j].rating = 0;
       					info[j].projects = 0;
       					info[j].people = 0;
       					info[j].hours = 0;
       				}
       			}
       		}
       	}
       	
       	//creating linked lists for 2 projects:
	for( i = 0; i < row && info[i].projects == 1; i++)
	{
		
		struct member top1 = {0, NULL, NULL, NULL };
		top1.next = (struct member *)malloc(sizeof(struct member)); 
		top1.next->id = info[i].id;
		top1.next->name = (char *)malloc(sizeof (info[i].name));
		strcpy(top1.next->name,info[i].name);	
		top1.next->prev = &top1;		
		top1.next->next = NULL;
	}
	for( i = 0; i < row && info[i].projects == 2; i++)
	{
		
		struct member top2 = {0, NULL, NULL, NULL };
		top2.next = (struct member *)malloc(sizeof(struct member)); 
		top2.next->id = info[i].id;
		top2.next->name = (char *)malloc(sizeof (info[i].name));
		strcpy(top2.next->name,info[i].name);	
		top2.next->prev = &top2;		
		top2.next->next = NULL;
	}
	struct member *prev;
	struct member *next;
	struct member top1 = {0, NULL, NULL, NULL };
		top1.next = (struct member *)malloc(sizeof(struct member)); 
	struct member *temp = top1.next;  // Assuming top1 is the head of the list

	while (temp != NULL)
	{
		printf("%d ", temp->id);
    		temp = temp->next;
	}
	
	// number of people working in project 1 and total manhrs spents in project 2
       printf("Question 1:\n");
       for(i = 0; i < row; i++)
       {
       		if ((info[i].projects) == 1)
       		p1++;
       }
       printf("number of people working in project 1 is %d\n",p1);
       printf("\n");
       int manhrs = 0;
       for(i = 0; i < row; i++)
       {
       		if (info[i].projects == 2)
       		{
       			manhrs = manhrs + info[i].hours;
       		}
       	}
       	printf("Total manhrs of project 2 is %d \n\n", manhrs);
       	printf("\n");
        //who reports to manager 
       	printf("Question 2:\n");
       	int empid = 0,manid = 0;
       	for(i = 0; i < row; i++)
       	{
       		if(strcmp(info[i].jobtitle,"manager") == 0 && info[i].id != manid)
       		{
       			printf("manager:%s\n", info[i].name);
       			manid = info[i].id;
       			for(j = 0; j < row; j++)
       			{
       				if (info[j].people == manid && info[j].id != empid)
       				{
       					printf("reporters:%s\n", info[j].name);
       					empid = info[j].id;
       				}
       			}
       		}
       	}
       	printf("\n");
       //who is who's boss
	printf("Question 3:\n");
       	printf("\n");
       	for(i = 1; i < row; i++)
       	{
       		if (info[i].people != 0)
       		{
       			manid = info[i].people;
       			for (j = 1; j < row; j++)
       			{
       				if(info[j].id == manid  && strcmp(info[j].status,"active") == 0 && info[j].id != info[j-1].id)
       				printf("%s is %s's boss in project %d\n",info[j].name,info[i].name,info[i].projects);
       			}
       		}
       		
       	}
       	printf("\n");
       	
       	// how many programmers are there i project 1:
       	printf("Question 4:\n");
       	int programmers1 = 0;
       	for(i = 0; i < row; i++)
       	{
       		if(strcmp(info[i].jobtitle,"programmer") == 0 && info[i].projects == 1)
       		programmers1 += 1;
       	}
       	printf("No. of programmers working in project 1: %d \n",programmers1);
       	printf("\n");
       // secretary not reporting to anyone
       	printf("Question 5:\n");
       	empid = 0;
       	for(i = 0; i < row; i++)
       	{
       		if(strcmp(info[i].jobtitle,"secretary") == 0)
       		{
       			for(j = 0; j < row; j++)
       			{
       				if(info[i].people == info[j].id && strcmp(info[j].status,"inactive") == 0 && info[j].id != empid)
       				{
       					printf("%s doesnot report to anyone\n",info[i].name);
       					empid = info[j].id;
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
       		for(j = 1; j < row; j++)
       		{
       			if(info[i].id == info[j].people)
       			num++;
       		}
       		if(num == 0 && i != 0 && info[i].id != info[i-1].id )
       		printf("%s has no one reporting to him\n",info[i].name);
       	}	
       	

	
	
	
	return 0;
}

//Output
/*
lekhasree@Lekhaubuntu:~/Documents$ gcc tr55.c
lekhasree@Lekhaubuntu:~/Documents$ ./a.out
0 Question 1:
number of people working in project 1 is 4

Total manhrs of project 2 is 45 


Question 2:
manager:anjali
reporters:ganesh

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
lekhasree@Lekhaubuntu:~/Documents$ 
*/
