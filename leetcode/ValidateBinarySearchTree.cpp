#include <iostream>
using namespace std;

struct TreeNode { 
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    bool isValidBST(TreeNode *node, int min, int max) {
        if (node == NULL)
            return true;
        if (node->val > max || node->val < min)
            return false;
        else 
            return isValidBST(node->left, min, node->val)
                && isValidBST(node->right, node->val, max);
    }
public:
    bool isValidBST(TreeNode *root) {
    	return isValidBST(root, INT_MIN, INT_MAX);
    }
};