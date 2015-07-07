#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
		int ldiv = 1, rdiv = 1, p = x;

		if (x < 0)
			return false;

		while (p > 9) {
			p = p / 10;
			ldiv = ldiv * 10;
		}

		int lvalue = x, rvalue = x;
		while (ldiv >= rdiv) {
			int ldigit = lvalue / ldiv;
			int rdigit = rvalue % 10;
			if(ldigit == rdigit) {
				lvalue -= ldigit * ldiv;
				rvalue = rvalue / 10;
				rdiv *= 10;
				ldiv /= 10;
			}
			else 
				return false;
		}
		return true;
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	cout << solution.isPalindrome(1001)<<endl;
	return 0;
}