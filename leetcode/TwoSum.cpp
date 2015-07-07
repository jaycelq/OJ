#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	class Node {
	public:
		int val;
		int index;
	};

	static bool less(const Node & a, const Node & b) {
		return a.val < b.val;
	}

    vector<int> twoSum(vector<int> &numbers, int target) {
        int i = 0, j = numbers.size() - 1; 
        vector<int> result;
        vector<Node> nodes(j+1);

        for(int k = 0; k <= j; k++) {
        	nodes[k].index = k;
        	nodes[k].val = numbers[k];
        }

        sort(nodes.begin(), nodes.end(), less);

        while(i < j) {
        	int left = nodes[i].val;
        	int right = nodes[j].val;
        	if(left + right > target)
        		j--;
        	else if(left + right < target)
        		i++;
        	else {
        		int left_index = nodes[i].index;
        		int right_index = nodes[j].index;
        		result.push_back(min(left_index, right_index) + 1);
        		result.push_back(max(left_index, right_index) + 1);
        		break;
        	}
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	int numbers_array [] = {2, 7, 11, 15};
	std::vector<int> numbers(numbers_array , 
		numbers_array + sizeof(numbers_array) / sizeof(int)); 
	vector<int> result = solution.twoSum(numbers, 13);
	cout << result[0] << " " << result[1] << endl;
	return 0;
}