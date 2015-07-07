//
// Created by Li Qiang on 15/6/4.
//


#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode *> leftFirstStack;
        stack<TreeNode *> rightFirstStack;
        vector<vector<int>> result;
        if (root == NULL)
            return result;
        bool leftFirst = false;
        rightFirstStack.push(root);

        while (rightFirstStack.empty() == false || leftFirstStack.empty() == false) {
            vector<int> levelVector;
            TreeNode *node;
            if (leftFirst == false)
            {
                while(rightFirstStack.empty() == false) {
                    node = rightFirstStack.top();
                    rightFirstStack.pop();
                    levelVector.push_back(node->val);
                    cout << "push_back" << node->val << endl;
                    if(node->left != NULL)
                        leftFirstStack.push(node->left);
                    if(node->right != NULL)
                        leftFirstStack.push(node->right);
                }
                leftFirst = true;
            }
            else if (leftFirst == true)
            {
                while(leftFirstStack.empty() == false) {
                    node = leftFirstStack.top();
                    leftFirstStack.pop();
                    levelVector.push_back(node->val);
                    if (node->right != NULL)
                        rightFirstStack.push(node->right);
                    if (node->left != NULL)
                        rightFirstStack.push(node->left);
                }
                leftFirst = false;
            }
            result.push_back(levelVector);
        }
        return result;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    Solution solution;
    vector<vector<int>> result = solution.zigzagLevelOrder(root);
    cout << result.size();
}