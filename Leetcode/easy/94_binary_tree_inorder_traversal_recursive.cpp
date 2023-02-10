#include <iostream>
#include <vector>

//Given the root of a binary tree, return the inorder traversal of its nodes' values.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution 
{
    std::vector<int> solution;
public:
    void solutionRecursive(TreeNode* current)
    {
        if(current == nullptr)
            return;

        solutionRecursive(current->left);
        solution.emplace_back(current->val);
        solutionRecursive(current->right);
    }

    std::vector<int> inorderTraversal(TreeNode* root) 
    {
        solutionRecursive(root);
        
        return solution;
    }
};