#include<iostream>
#include <fstream>
using namespace std;
#define MAX 1000
int A[MAX][MAX];//save the length
int D[MAX][MAX];//save the points the path through 

int main(void)
{
	int i,j,k,x,y,z;
	int point_num,path_num;//number of points, number of paths
	ifstream  readFile("D:\\Floyd_Test.txt");
	readFile>>point_num>>path_num;

	for(i=0;i<point_num;i++)//initial
	{
		for(j=0;j<point_num;j++)
		{
			if(i==j)
				A[i][j]=0;
			else
				A[i][j]=MAX;
			D[i][j]=MAX;//means link straight
		}
	}

	while(!readFile.eof())//read file
	{
		readFile>>x>>y>>z;
		if(x<point_num&&y<point_num)
		{
			A[x][y]=z;
			D[x][y]=x+1;
		}
	}

	for(k=0;k<point_num;k++)
		for(i=0;i<point_num;i++)
			for(j=0;j<point_num;j++)
			{
				if(A[i][j]>A[i][k]+A[k][j]&&A[i][k]+A[k][j]!=0)
				{
					A[i][j]=A[i][k]+A[k][j];
					D[i][j]=D[k][j];
				}
			}

	for(i=0;i<point_num;i++)//print A[][]
	{
		for(j=0;j<point_num;j++)
		{
			cout <<A[i][j]<<"\t";
		}
		printf("\n");
	}
	printf("\n\n");
	for(i=0;i<point_num;i++)//print D[][]
	{
		for(j=0;j<point_num;j++)
		{
			cout <<D[i][j]<<"\t";
		}
		printf("\n");
	}
	printf("\n\n");

	for(i=0;i<point_num;i++)
	{
		for(j=0;j<point_num;j++)
		{
			if(A[i][j]==MAX)//A[i][j]==0||
			{
				//cout <<"point"<<i<<"to point"<<j<<": ";
				//cout <<"---"<<endl;
			}
			else
			{
				cout <<"point "<<i+1<<" -> point "<<j+1<<"\t";
				cout <<"length:"<<A[i][j]<<"\t";
				cout <<"path:\t";
				//print the path
				cout<<j+1;
				int pat = D[i][j];
				while (pat!=MAX)
				{
					printf("<-%d",pat);
					pat=D[i][pat-1];
				}
				cout <<endl;
			}
		}
	}

	return 0;
}
