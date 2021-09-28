//https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/

class Solution {
public:
    void solve(TreeNode* root,TreeNode* parent,int&ans)
    {
        if(root==NULL)
            return;
        
        if(root->left!=NULL)
        {
            if(parent->val%2==0 && root!=parent)
                ans+=root->left->val;
            solve(root->left,root,ans);
        }
        if(root->right!=NULL)
        {
            if(parent->val%2==0 && root!=parent)
                ans+=root->right->val;
            solve(root->right,root,ans);
        }
    }
    int sumEvenGrandparent(TreeNode* root) {
        int ans = 0;
        solve(root,root,ans);
        return ans;
    }
};
