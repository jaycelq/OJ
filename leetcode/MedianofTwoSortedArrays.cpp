#include <iostream>
using namespace std;

class Solution {
private:
	double findKthElement(int A[], int m, int B[], int n, int k) {
		if(m < n)
			return findKthElement(B, n, A, m, k);

		if (n == 0)
			return A[k-1];

		if (k == 1)
			return min((double)A[0], (double)B[0]);

		int p = k/2, q = k - k/2;

		if(p > n) {
			p = n;
			q = k - p;
		}

		int left_val = A[q-1], right_val = B[p-1];

		if(left_val == right_val)
			return (double)left_val;
		else if(left_val < right_val) 
			return findKthElement(A + q, m - q, B, n, k - q);
		else
			return findKthElement(A, m, B + p, n - p, k - p);
	}

public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int amount = m + n;

        if(amount % 2 == 1)
        	return findKthElement(A, m, B, n, (m+n)/2 + 1);
        else {
        	return (findKthElement(A, m, B, n, (m+n)/2) + 
        		findKthElement(A, m, B, n, (m+n)/2 + 1))/2;
        }
    }
    
};

int main(int argc, char const *argv[])
{
	Solution solution;
	int a [] = {1, 2};
	int b [] = {1, 2};
	cout << solution.findMedianSortedArrays(a, 2, b, 2) << endl;
	return 0;
}