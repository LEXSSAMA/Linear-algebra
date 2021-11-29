#include <vector>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

template<typename T>
void printMatrix(std::vector<std::vector<T>>& matrix)
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
int LU_Factorization( std::vector<std::vector<T>>& L , std::vector<std::vector<T>> & U)
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
template< typename T >
int inputMatrix(std::vector<std::vector<T>>& matrix)
{
    std::ifstream fp;
    std::string matrixNum;
    int rowSize = 0;
    fp.open("./matrix",std::ios::in);
    while(std::getline(fp,matrixNum))
    {
        std::size_t pos = 0;
        std::size_t endPos = 0;
        matrix.push_back(std::vector<T>());
        while((endPos=matrixNum.find(" ",pos)) != std::string::npos)
        {
            std::string s = matrixNum.substr(pos,endPos-pos);
            matrix[rowSize].push_back((T)std::stoi(matrixNum.substr(pos,endPos)));
            pos = endPos+1;
        }
        matrix[rowSize].push_back(std::stoi(matrixNum.substr(pos,matrixNum.length())));
        rowSize++;
    }

    fp.close();
    return 0;
}

int main()
{

    std::vector< std::vector<double>> A;
    inputMatrix(A);

    int rowSize    = A.size();
    int columnSize = A[0].size();


    std::vector< std::vector<double> > U(A);
    std::vector< std::vector<double> > L(rowSize,std::vector<double>(rowSize,0));

    LU_Factorization(L,U);

    printf("L matrix:\n");
    printMatrix(L);
    printf("U matrix: \n");
    printMatrix(U);
    return 0;
}
