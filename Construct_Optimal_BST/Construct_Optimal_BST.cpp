#include<iostream>
using namespace std;
#define MAX 6

int root[MAX][MAX] = {
    0, 0, 0, 0, 0, 0,  
    0, 1, 1, 2, 2, 2,  
    0, 0, 2, 2, 2, 4,  
    0, 0, 0, 3, 4, 5,  
    0, 0, 0, 0, 4, 5,  
    0, 0, 0, 0, 0, 5,  
};

void CONSTRUCT_OPTIMAL_BST(int i, int j)
{
	int s = root[i][j];
	if(i==1&&j==MAX-1)
		cout << "k" << root[i][j] << " is root" << endl;
	if(i>s-1)
		cout << "d" << root[i][j] - 1 << " is k" << root[i][j] << "'s left child" << endl;
	else
	{
		cout << "k" << root[i][s-1] << " is k" << root[i][j] << "'s left child" << endl;
		CONSTRUCT_OPTIMAL_BST(i, root[i][j] - 1);
	}
	if(j<s+1)
		cout << "d" << root[i][j] << " is k" << root[i][j] << "'s right child" << endl;
	else
	{
		cout << "k" << root[s+1][j] << " is k" << root[i][j] << "'s right child" << endl;
		CONSTRUCT_OPTIMAL_BST(root[i][j]+1, j);
	}
}  
  
int main(void)  
{  
    CONSTRUCT_OPTIMAL_BST(1, MAX-1);  
    return 0;
}  
