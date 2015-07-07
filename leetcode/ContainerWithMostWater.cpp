//
// Created by Li Qiang on 15/5/30.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int low = 0, high = height.size() - 1;

        int result = 0;
        while(low < high) {
            int area = min(height[low], height[high]) * (high - low);
            result = max(result, area);
            if(height[low] < height[high])
                low++;
            else
                high--;
        }
        return result;
    }
};

int main(){
    Solution solution;
    vector<int> height {3,2,10,1,11,2,4};
    cout << solution.maxArea(height)<<endl;
    return 0;
}