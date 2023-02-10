#include <iostream>
#include <vector>
#include <stack>

//Given the root of a binary tree, return the inorder traversal of its nodes' values.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) 
    {
        std::vector<int> solution;

        TreeNode* current = root;
        std::stack<TreeNode*> visitedLocations;
        visitedLocations.push(nullptr);

        while(current)
        {
            if(current == visitedLocations.top())
            {
                visitedLocations.pop();
            }
            else if(current->left)
            {
                visitedLocations.push(current);
                current = current->left;
                continue;
            }

            solution.emplace_back(current->val);

            if(current->right)
            {
                current = current->right;
            }
            else if(visitedLocations.empty())
            {
                current = nullptr;
            }
            else
            {
                current = visitedLocations.top();
            }
        }
        
        return solution;
    }
};

int main()
{
    Solution solution;
    TreeNode* root;
    TreeNode n3 = TreeNode(3);
    TreeNode n2 = TreeNode(2, &n3, nullptr);
    TreeNode n1 = TreeNode(1, nullptr, &n2);
    root = &n1;

    auto sol = solution.inorderTraversal(root);
    for (auto item : sol)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}