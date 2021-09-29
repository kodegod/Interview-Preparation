//https://leetcode.com/problems/diameter-of-binary-tree/

class Solution {
public:
    int ans = 0;
    int dia(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int d1=dia(root->left);
        int d2=dia(root->right);
        ans=max(ans,1+d1+d2);
        return 1+max(d1,d2);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int x = dia(root);
        return ans-1;
    }
};
