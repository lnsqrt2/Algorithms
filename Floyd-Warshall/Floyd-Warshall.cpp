#include<iostream>
using namespace std;
#define MAX 1000
int d[MAX][MAX];
int path[MAX][MAX];


int main(void)
{
	int i=0;
	int m,n;//m number of points, n number of paths
	ifstream  readFile("D:\\Floyd_Test.txt");
	readFile>>m>>n;
	while(!readFile.eof())//read file
	{
		readFile>>p[i].x>>p[i].y;
		i++;
		n++;
	}
	return 0;
}