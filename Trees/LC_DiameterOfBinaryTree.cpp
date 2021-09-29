//https://leetcode.com/problems/diameter-of-binary-tree/

class Solution {
public:
    int ans = -1;
    int dia(TreeNode* root)
    {
        if(root->left==NULL && root->right==NULL)
            return 0;
        int d1=-1;
        int d2=-1;
        if(root->left!=NULL)
            d1=dia(root->left);
        if(root->right!=NULL)
            d2=dia(root->right);
        ans=max(ans,1+d1+d2);
        return 1+max(d1,d2);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int x = dia(root);
        return ans+1;
    }
};
