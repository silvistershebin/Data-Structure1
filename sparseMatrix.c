#include<stdio.h>
#include<stdlib.h>
#define MAX_TERMS 15
void create_matrix(int a[MAX_TERMS][MAX_TERMS],int , int);
typedef struct{
	int cols;
	int rows;
	int value;
}term;
void create_matrix(int a[MAX_TERMS][MAX_TERMS],int rows, int cols)
{
	int i,j;
	for(i=0;i<rows;i++)
	{
		for(j=0;j<cols;j++)
		{
			printf("Position %d.%d : ",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}
}

void display_matrix(int a[MAX_TERMS][MAX_TERMS],int rows, int cols)
{
	int i,j;
	printf("The entered matrix is as follows: \n");
	for(i=0;i<rows;i++)
	{
		for(j=0;j<cols;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}

void convert_matrix(term x[MAX_TERMS],int a[MAX_TERMS][MAX_TERMS],int rows, int cols)
{
	int count=1,i,j;
	x[0].rows = rows;
	x[0].cols = cols;
	for(i=0;i<rows;i++)
	{
		for(j=0;j<cols;j++)
		{
			if(a[i][j]!=0)
			{
				x[count].rows = i;
				x[count].cols = j;
				x[count].value = a[i][j];
				count++;
			}
		}
	}
	x[0].value = count-1;
	printf("\n");
	printf("The converted matrix is: \n");
	printf("Row\tCol\tValue");
	printf("\n");
	for(i=0; i<=x[0].value; i++)
	{
		printf("%d\t%d\t%d",x[i].rows,x[i].cols,x[i].value);
		printf("\n");	
	}
}
void simple_transpose(term src[MAX_TERMS],term dest[MAX_TERMS])
{
	dest[0].cols = src[0].rows;
	dest[0].rows = src[0].cols;
	dest[0].value = src[0].value;
	int count=1,i,j;
	for(i=0;i<src[0].cols;i++)
	{
		for(j=1;j<=src[0].value;j++)
		{
			if(src[j].cols==i)
			{
				dest[count].rows = src[j].cols;
				dest[count].cols = src[j].rows;
				dest[count].value = src[j].value;
				count++;
			}
		}
	}
	printf("\n");
	printf("The transpose of the matrix is: \n");
	printf("Row\tCol\tValue");
	printf("\n");
	for(i=0; i<=dest[0].value; i++)
	{
		printf("%d\t%d\t%d",dest[i].rows,dest[i].cols,dest[i].value);
		printf("\n");	
	}
}
void shonil_method(term src[MAX_TERMS],term dest[MAX_TERMS])
{
	int n = src[0].value,i,j;
	while(n>=0)
	{
		dest[n].rows = src[n].cols;
		dest[n].cols = src[n].rows;
		dest[n].value = src[n].value;
		n--;
	}
	n = src[0].value;
	term temp;
	for(i=0;i<n-1;i++)
	{
		for(j=1;j<=n-i-1;j++)
		{
			if(dest[j].value>dest[j+1].value)
			{
				temp = dest[j];
				dest[j] = dest[j+1];
				dest[j+1] = temp;
			}
		}
	}
	printf("\n");
	printf("The transpose of the matrix is: \n");
	printf("Row\tCol\tValue");
	printf("\n");
	for(i=0; i<=dest[0].value; i++)
	{
		printf("%d\t%d\t%d",dest[i].rows,dest[i].cols,dest[i].value);
		printf("\n");	
	}
}
void fast_transpose(term a[MAX_TERMS], term b[MAX_TERMS])
{
	int startpos[a[0].cols], rowterm[a[0].cols];
	startpos[0] = 1;
	int i,j;
	b[0].cols = a[0].rows;
	b[0].rows = a[0].cols;
	b[0].value = a[0].value;
	for(i=0;i<a[0].cols;i++)
		{rowterm[i] = 0;
		}
		
	for(i=1;i<=a[0].value;i++)
		{rowterm[a[i].cols] = rowterm[a[i].cols] + 1;
		}
	for(i=1;i<a[0].cols;i++)
		{startpos[i] = startpos[i-1] + rowterm[i-1];
		}
	for(i=1;i<=a[0].value;i++)
	{
		j = startpos[a[i].cols];
		startpos[a[i].cols] = startpos[a[i].cols] + 1;
		b[j].rows = a[i].cols;
		b[j].cols = a[i].rows;
		b[j].value = a[i].value;
	}
	printf("\n");
	printf("The transpose of the matrix is: \n");
	printf("Row\tCol\tValue");
	printf("\n");
	for(i=0; i<=b[0].value; i++)
	{
		printf("%d\t%d\t%d",b[i].rows,b[i].cols,b[i].value);
		printf("\n");	
	}
}

void main()
{
	term x[MAX_TERMS];
	int rows,cols,choice,flag=0;
	while(flag==0)
	{
	printf("MENU\n1.Accept Conventional Matrix\n2.Display Conventional matrix and compact form representation\n3.Simple Transpose\n4.Shonil Method\n5.Fast Transpose\n6.Exit\nEnter your choice.... ");
	scanf("%d",&choice);
		switch(choice)
		{
			case 1:	printf("Enter the number of rows of the sparse matrix: ");
				scanf("%d",&rows);
				printf("Enter the number of columns of the sparse matrix: ");
				scanf("%d",&cols);
				printf("Enter the values of the matrix:\n");
				int a[MAX_TERMS][MAX_TERMS];
				create_matrix(a,rows,cols);
				break;
			case 2:	display_matrix(a,rows,cols);
				convert_matrix(x,a,rows,cols);
				break;
			case 3:	{
				term y[MAX_TERMS];
				simple_transpose(x,y);
				break;
				}
			case 4: {
				term y[MAX_TERMS];
				shonil_method(x,y);
				break;
				}
			case 5:
				{
				term y[MAX_TERMS];				
				fast_transpose(x,y);
				break;
				}
			case 6:flag=1;
				break;
			default:printf("You have entered an invalid choice. Please try again.\n");
		}
	}

}

/*
OUTPUT:
student@B4L0106:~/Desktop$ ./a.out
MENU
1.Accept Conventional Matrix
2.Display Conventional matrix and compact form representation
3.Simple Transpose
4.Shonil Method
5.Fast Transpose
6.Exit
Enter your choice.... 1
Enter the number of rows of the sparse matrix: 6
Enter the number of columns of the sparse matrix: 6
Enter the values of the matrix:
Position 1.1 : 15 0 0 22 0 -15 0 11 3 0 0 0 0 0 0 -6 0 0 0 0 0 0 0 0 91 0 0 0 0 0 0 0 28 0 0
Position 1.2 : Position 1.3 : Position 1.4 : Position 1.5 : Position 1.6 : Position 2.1 : Position 2.2 : Position 2.3 : Position 2.4 : Position 2.5 : Position 2.6 : Position 3.1 : Position 3.2 : Position 3.3 : Position 3.4 : Position 3.5 : Position 3.6 : Position 4.1 : Position 4.2 : Position 4.3 : Position 4.4 : Position 4.5 : Position 4.6 : Position 5.1 : Position 5.2 : Position 5.3 : Position 5.4 : Position 5.5 : Position 5.6 : Position 6.1 : Position 6.2 : Position 6.3 : Position 6.4 : Position 6.5 : Position 6.6 : 0
MENU
1.Accept Conventional Matrix
2.Display Conventional matrix and compact form representation
3.Simple Transpose
4.Shonil Method
5.Fast Transpose
6.Exit
Enter your choice.... 2
The entered matrix is as follows: 
15	0	0	22	0	-15	
0	11	3	0	0	0	
0	0	0	-6	0	0	
0	0	0	0	0	0	
91	0	0	0	0	0	
0	0	28	0	0	0	

The converted matrix is: 
Row	Col	Value
6	6	8
0	0	15
0	3	22
0	5	-15
1	1	11
1	2	3
2	3	-6
4	0	91
5	2	28
MENU
1.Accept Conventional Matrix
2.Display Conventional matrix and compact form representation
3.Simple Transpose
4.Shonil Method
5.Fast Transpose
6.Exit
Enter your choice.... 5

The transpose of the matrix is: 
Row	Col	Value
6	6	8
0	0	15
0	4	91
1	1	11
2	1	3
2	5	28
3	0	22
3	2	-6
5	0	-15
MENU
1.Accept Conventional Matrix
2.Display Conventional matrix and compact form representation
3.Simple Transpose
4.Shonil Method
5.Fast Transpose
6.Exit
Enter your choice.... 6
*/
