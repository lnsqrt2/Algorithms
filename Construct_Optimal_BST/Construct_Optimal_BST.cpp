#include<iostream>  
using namespace std;  
int root[6][6] = {   
    0, 0, 0, 0, 0, 0,  
    0, 1, 1, 2, 2, 2,  
    0, 0, 2, 2, 2, 4,  
    0, 0, 0, 3, 4, 5,  
    0, 0, 0, 0, 4, 5,  
    0, 0, 0, 0, 0, 5,  
};  
  
void CONSTRUCT_OPTIMAL_BST(int i, int j, int flag){  
    if (i <= j){  
        if (flag == 1){  
            cout << "k" << root[i][j] << "为根" << endl;  
        }  
        else if (flag == 0){  
            cout << "k" << root[i][j] << "为k" << j + 1 << "的左孩子" << endl;  
        }  
        else{  
            cout << "k" << root[i][j] << "为k" << i - 1 << "的右孩子" << endl;  
        }  
        CONSTRUCT_OPTIMAL_BST(i, root[i][j] - 1, 0);  
        CONSTRUCT_OPTIMAL_BST(root[i][j] + 1, j, 2);  
    }  
    else if (j == (i - 1)){  
        if (flag == 0){  
            cout << "d" << j << "为k" << j + 1 << "的左孩子" << endl;  
        }  
        else if (flag == 2){  
            cout << "d" << j << "为k" << i - 1 << "的右孩子" << endl;  
        }  
    }  
}  
  
void main()  
{  
    CONSTRUCT_OPTIMAL_BST(1, 5, 1);  
}  