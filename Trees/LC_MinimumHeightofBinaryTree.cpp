//https://leetcode.com/problems/minimum-depth-of-binary-tree/

class Solution {
public:
    int solve(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        
        if(root->left==NULL && root->right==NULL)
            return 1;
        
        int a = INT_MAX;
        int b = INT_MAX;
        
        if(root->left!=NULL)
            a = solve(root->left);
        if(root->right!=NULL)
            b = solve(root->right);
        
        return 1 + min(a,b);
    }
    int minDepth(TreeNode* root) {
        return solve(root);
    }
};
