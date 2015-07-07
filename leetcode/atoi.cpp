#include <iostream>
using namespace std;

class Solution {
public:
    int atoi(string str) {
        int i = 0, result = 0;
        bool positive = true;

        for (; i < str.length(); i++) {
        	if(str[i] == ' ')
        		continue;
        	else if(str[i] == '-') {
        		positive = false;
        		i++;
        		break;
        	}
        	else if(str[i] == '+') {
        		i++;
        		break;
        	}
        	else
        		break;

        }

        for (; i < str.length(); i++) {
        	int digit = str[i] - '0';
        	if(digit >= 0 && digit <= 9) {
        		if(positive == true) {
        			if((INT_MAX - digit)/10 < result) {
        				result = INT_MAX;
        				break;
        			}
        			else {
        				result = result * 10 + digit;
        			}
        		}
        		else if(positive == false) {
        			if((INT_MIN + digit)/10  > result) {
        				result = INT_MIN;
        				break;
        			}
        			else {
        				result = result * 10 - digit;
        			}
        		}
        	}
        	else 
        		break;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	cout << solution.atoi("-2147483648") << endl;
	return 0;
}