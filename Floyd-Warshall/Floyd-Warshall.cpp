#include<iostream>
using namespace std;
#define MAX 1000
int d[MAX][MAX];
int path[MAX][MAX];


int main(void)
{
	int i=0;
	ifstream  readFile("D:\\Floyd_Test.txt");
	while(!readFile.eof())//read file
	{
		readFile>>p[i].x>>p[i].y;
		i++;
		n++;
	}
	return 0;
}