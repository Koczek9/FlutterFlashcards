//Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

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
    bool result(TreeNode* a, TreeNode* b)
    {
        if(!a && !b)
            return true;
        else if(!a || !b)
            return false;

        if(a->val != b->val)
            return false;

        return result(a->right, b->left) && result(a->left, b->right);
    }
    bool isSymmetric(TreeNode* root) 
    {
        if(!root)
            return true;
        
        return result(root->right, root->left);
    }
};