//https://leetcode.com/problems/invert-binary-tree/

class Solution {
public:
    void mirror(TreeNode* root)
    {
        if(root==NULL)
            return;
        TreeNode* temp = root->left;
        root->left=root->right;
        root->right=temp;
        mirror(root->left);
        mirror(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        mirror(root);
        return root;
    }
};
