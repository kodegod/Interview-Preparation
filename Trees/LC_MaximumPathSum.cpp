//https://leetcode.com/problems/binary-tree-maximum-path-sum/

class Solution {
public:
    int ans = INT_MIN;
    int solve(TreeNode *root)
    {
        if(root == NULL)
            return 0;
        int a = solve(root->left);
        int b = solve(root->right);
        
        ans = max(ans, a + root->val + b);
        ans = max(ans, max(a + root->val,b+ root->val));
        ans = max(ans, root->val);
        return max(root->val, max(a + root->val,b + root->val));
    }
    int maxPathSum(TreeNode* root) {
        int k = solve(root);
        return ans;
    }
};
