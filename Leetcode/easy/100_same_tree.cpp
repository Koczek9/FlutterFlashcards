#include<iostream>

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
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if(!p && !q)
            return true;
        else if(!p || !q)
            return false;

        if(p->val != q->val)
            return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main()
{
    Solution solution;
    TreeNode* p;
    TreeNode p2 = TreeNode(2);
    TreeNode p1 = TreeNode(1, &p2, nullptr);
    p = &p1;

    TreeNode* q;
    TreeNode q2 = TreeNode(2);
    TreeNode q1 = TreeNode(1, nullptr, &p2);
    q = &q1;

    std::cout << solution.isSameTree(p, q) << std::endl;
}