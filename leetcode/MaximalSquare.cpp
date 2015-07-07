//
// Created by Li Qiang on 15/6/5.
//

#include <vector>
#include <iostream>
using namespace std;

int maximalSquare(vector<vector<char> >& matrix) {
    int iMatrixHeight = matrix.size();
    if(iMatrixHeight == 0)
        return 0;
    int iMatrixWidth = matrix[0].size();

    int **dpTable = new int* [iMatrixHeight + 1];
    for (int i = 0; i < iMatrixHeight + 1; i++)
    {
        dpTable[i] = new int [iMatrixWidth + 1];
        memset(dpTable[i], 0, (iMatrixWidth + 1)*sizeof(int));
    }


    int result = 0;
    for (int i = 0; i < iMatrixHeight; i++)
    {
        for (int j = 0; j < iMatrixWidth; j++)
        {
            if(matrix[i][j] == '0')
                dpTable[i+1][j+1] = 0;
            else
                dpTable[i+1][j+1] = min(min(dpTable[i][j], dpTable[i][j+1]), dpTable[i+1][j]) + 1;
            result = max(result, dpTable[i+1][j+1]);
        }
    }


    for (int i = 0; i < iMatrixHeight + 1; i++)
    {
        delete [] dpTable[i];
    }
    delete [] dpTable;

    return result*result;
}

int main()
{
    vector<vector<char> > matrix;
    vector<char> row;
    int width, height;

    cin>> width >> height;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            char ch;
            cin >> ch;
            row.push_back(ch);
        }
        matrix.push_back(row);
        row.clear();
    }

    cout << maximalSquare(matrix) << endl;

    return 0;
}