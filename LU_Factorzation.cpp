#include <vector>
#include <stdio.h>
using namespace std;


template<typename T>
void printMatrix(vector<vector<T>>& matrix)
{
    int rowSize    = matrix.size();
    int columnSize = matrix[0].size();

    for(int row=0; row<rowSize;++row)
    {
        for(int col=0; col<columnSize;++col)
        {
            printf("%.1lf ",(double)matrix[row][col]);
        }
        printf("\n");
    }
    return ;
}

//杜尔利特算法
template<typename T>
int LU_Factorization( vector<vector<T>>& L , vector<vector<T>> & U)
{
    int columnSize = U[0].size();
    int rowSize    = U.size();
    // make diagonal element equal to 1
    for(int i=0;i<rowSize;++i)
    {
        L[i][i] = 1;
    }
    // increase column index from 0 to the number of A matrix column 
    for(int col=0;col<columnSize;++col)
    {
        int index = col;
        // increase row index
        for(int row=col+1; row<rowSize;++row)
        {
            double tmp = U[row][index]/U[index][index];
            L[row][index] = tmp;

            for(int i=index; i<columnSize;++i)
            {
                U[row][i] -= (tmp * U[index][i]);
            }
        }
    }
    return 0;
}

int main()
{
    vector< vector<double> > A{ {1.0,2.0,3.0},
                                {4.0,5.0,6.0},
                                {7.0,8.0,11.0},
                              };

    int rowSize    = A.size();
    int columnSize = A[0].size();

    vector< vector<double> > U(A);
    vector< vector<double> > L(rowSize,vector<double>(rowSize,0));

    LU_Factorization(L,U);

    printf("L matrix:\n");
    printMatrix(L);
    printf("U matrix: \n");
    printMatrix(U);
    return 0;
}
