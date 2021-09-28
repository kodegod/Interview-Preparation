//https://leetcode.com/problems/sum-of-left-leaves/

class Solution {
public:
    void solve(TreeNode* root,int&ans)
    {
        if(root==NULL)
            return;
        if(root->left!=NULL)
            if(root->left->left == NULL && root->left->right==NULL)
                ans+=root->left->val;
        solve(root->left,ans);
        solve(root->right,ans);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        solve(root,ans);
        return ans;
    }
};
