//
// Created by Li Qiang on 15/6/7.
//
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int maximalRectangleInHist(vector<int> &vHist) {
    int i = 0;
    int result = 0;
    stack<int> indexStack;

    for ( i = 0; i < vHist.size(); i++) {
        if(indexStack.empty() || vHist[indexStack.top()] < vHist[i]) {
            indexStack.push(i);
        }
        else {
            while (indexStack.empty() == false && vHist[indexStack.top()] > vHist[i]) {
                int index = indexStack.top();
                indexStack.pop();

                int left = indexStack.empty() ? 0 : indexStack.top() + 1;
                result = max(result, (i - left) * vHist[index]);
            }
            indexStack.push(i);
        }
    }

    while (indexStack.empty() == false) {
        int index = indexStack.top();
        indexStack.pop();

        int left = indexStack.empty() ? 0 : indexStack.top() + 1;
        result = max(result, (i - left)* vHist[index]);
    }

    return result;
}


int maximalRectangle(vector<vector<char>>& matrix) {
    int height = matrix.size();
    if (height == 0)
        return 0;
    int width = matrix[0].size();
    vector<int> vCache(width, 0);
    int result = 0;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if(matrix[i][j] == '0')
                vCache[j] = 0;
            else
                vCache[j] += 1;
        }
        result = max(result, maximalRectangleInHist(vCache));
    }

    return result;

}

int main() {
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

    cout << maximalRectangle(matrix) << endl;

    return 0;
}