//https://leetcode.com/problems/boundary-of-binary-tree/

vector<int> leftb;
vector<int> rightb;
vector<int> leaf;

class Solution {
public:
    void lb(TreeNode* root)
    {
        if(root == NULL)
            return;
        if(root->left == NULL && root->right == NULL)
            return;
        leftb.push_back(root->val);
        if(root->left!=NULL)
            lb(root->left);
        else
            lb(root->right);
    }
    void rb(TreeNode *root)
    {
        if(root == NULL)
            return;
        if(root->left == NULL && root->right == NULL)
            return;
        if(root->right!=NULL)
            rb(root->right);
        else
            rb(root->left);
        rightb.push_back(root->val);
    }
    void leafy(TreeNode *root)
    {
        if(root == NULL)
            return;
        if(root->left == NULL && root->right ==NULL)
        {
            leaf.push_back(root->val);
            return;
        }
        leafy(root->left);
        leafy(root->right);
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        leftb.clear();
        rightb.clear();
        leaf.clear();
        vector<int> ans;
        if(root->left!= NULL || root->right!= NULL)
            ans.push_back(root->val);
        lb(root->left);
        rb(root->right);
        leafy(root);
        for(auto it:leftb)
            ans.push_back(it);
        for(auto it:leaf)
            ans.push_back(it);
        for(auto it:rightb)
            ans.push_back(it);
        return ans;
    }
};
