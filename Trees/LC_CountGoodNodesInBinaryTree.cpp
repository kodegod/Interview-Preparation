//https://leetcode.com/problems/count-good-nodes-in-binary-tree/

class Solution {
public:
    void solve(TreeNode* root, int maxy,int&ans)
    {
        // base case
        if(root==NULL)
            return;
        
        if(root->val >= maxy)
            ans++;
        
        if(root->left!=NULL)
            solve(root->left,max(maxy,root->left->val),ans);
        if(root->right!=NULL)
            solve(root->right,max(maxy,root->right->val),ans);
    }
    int goodNodes(TreeNode* root) {
        int ans = 0;
        solve(root,root->val,ans);
        return ans;
    }
};
