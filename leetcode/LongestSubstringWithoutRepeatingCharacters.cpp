#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int flags [256] = {0};
        int start = 0, length = s.length();
        int result = 0;

        for(int i = 0; i < s.length(); i++) {
        	if(flags[s[i]] == 0) {
        		flags[s[i]] = 1;
        		result = max(result, i - start + 1);
        	}
        	else {
        		for (int k = start; k < i; k++) {
        			if(s[k] != s[i])
        				flags[s[k]] = 0;
        			else {
        				start = k + 1;
        				break;
        			}
        		}
        	}
        }

        return result;
    }
};

int main()
{
	Solution solution;
	string a = "umvejcuuk";
	cout << solution.lengthOfLongestSubstring(a) << endl;
	return 0;
}