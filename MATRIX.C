#include<stdio.h>
#include<conio.h>
int i,j,k,a,b;
int main()
{
	int row,col,rank=0,x;
	float temp,tem;
	float mat[80][80];
	clrscr();
	printf("**********************************************\n");
	printf("Convert any m x n matrix into Row Echelon Form\n");
	printf("Enter The number of row : ") ;
	scanf("%d",&row);
	printf("Enter The number of colums : ") ;
	scanf("%d",&col);
	printf("Enter Number of Unknown: ");
	scanf("%d",&x);
	for(i=0;i<row;i++)
	{
	  for(j=0;j<col;j++)
	   {
	    printf("Enter the %d %d Element: ",i+1,j+1);
	    scanf("%f",&mat[i][j]);
	   }
	}
	printf("Your Matrix is :: \n");
	for(i=0;i<row;i++)
	{
	  for(j=0;j<col;j++)
	   {
	    printf("%.1f\t",mat[i][j]);
	   }
	  printf("\n");
	}
	for(k=0;k<row;k++)
	{
		if((mat[k][k]) != 1)
		{
			temp = mat[k][k];
			if(temp == 0)
			 continue;
			for(j=0;j<col;j++)
			{
			mat[k][j] = ( (mat[k][j]) /temp);
			}
		}
		for(i=k+1;i<row;i++)
		{
			tem = mat[i][k];
			for(j=k;j<col;j++)
			{
			mat[i][j]= mat[i][j] - (mat[k][j]*tem);
			}
		}
		printf("\n*********************************\n");
		if(k==row-1)
		printf("Row Echelon Form is: \n\n");
		else
		printf("step %d\n\n",k+1);
		for(a=0;a<row;a++)
		{
			for(b=0;b<col;b++)
			{
			if(mat[a][b] == -0)
			mat[a][b] = 0;
			printf("%.1f\t",mat[a][b]);
			}
			printf("\n");
		}
	}

	for(i=0;i<row;i++)
	{
	  for(j=0;j<col;j++)
	    {
	      if(mat[i][j]!=0)
	       {
		rank++;
		break;
	       }
	    }
	}
		printf("***********\n");
		printf("Rank : %d\n",rank);
		if(rank==x)
		{
			printf("The Given Vector is Linear Independent");

		}
		else
		{
			printf("The given Vector Is Linear Dependent");
		}
getch();
}