#include <iostream>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int result = 0, i = 0;

        while (i < s.length()) {
        	int tmp = 0;
        	switch(s[i]) {
        		case 'M' :
        			tmp = 1000;
        			i++;
        			while (s[i] == 'M') {
        				tmp += 1000;
        				i++;
        			}
        			break;
        		case 'D' :
        			tmp = 500;
        			i++;
        			break;
        		case 'C' :
        			tmp = 100;
        			i++;
        			while (s[i] == 'C') {
        				tmp += 100;
        				i++;
        			}
        			if (s[i] == 'D') {
        				tmp = 500 - tmp;
        				i++;
        			}
        			if (s[i] == 'M') {
        				tmp = 1000 - tmp;
        				i++;
        			}
        			break;
        		case 'L' :
        			tmp = 50;
        			i++;
        			break;
        		case 'X' :
        			tmp = 10;
        			i++;
        			while (s[i] == 'X') {
        				tmp += 10;
        				i++;
        			}

        			if(s[i] == 'L') {
        				tmp = 50 - tmp;
        				i++;
        			}

        			if(s[i] == 'C') {
        				tmp = 100 - tmp;
        				i++;
        			}
        			break;
        		case 'V' :
        			tmp = 5;
        			i++;
        			break;
        		case 'I' :
        			tmp = 1;
        			i++;
        			while (s[i] == 'I') {
        				tmp += 1;
        				i++;
        			}
        			if(s[i] == 'V') {
        				tmp = 5 - tmp;
        				i++;
        			}
        			if(s[i] == 'X') {
        				tmp = 10 - tmp;
        				i++;
        			}
        			break;
        	}
        	result += tmp;
        }
        return result;

    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	cout << solution.romanToInt("MCMXCVI") << endl;	
	return 0;
}