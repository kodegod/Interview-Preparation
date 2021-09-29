//https://leetcode.com/problems/cousins-in-binary-tree/

map<int,int> depth;
map<int,int> par;

class Solution {
public:
    void preorder(TreeNode* root,int lvl)
    {
        if(root==NULL)
            return;
        depth[root->val] = lvl;
        if(root->left!=NULL)
            par[root->left->val]=root->val;
        if(root->right!=NULL)
            par[root->right->val]=root->val;
        preorder(root->left,lvl+1);
        preorder(root->right,lvl+1);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        preorder(root,0);
        if(par[x]==par[y])
            return false;
        if(depth[x]==depth[y])
            return true;
        return false;
    }
};
