//https://leetcode.com/problems/symmetric-tree/

class Solution {
public:
    bool compare(TreeNode* root1, TreeNode* root2)
    {
        if(root1 == NULL && root2 == NULL)
            return true;
        else if(root1 == NULL || root2 == NULL)
            return false;
        
        if(root1->val != root2->val)
            return false;
        return (compare(root1->left,root2->right) && compare(root1->right,root2->left));
    }
    
    bool isSymmetric(TreeNode* root) {
        return compare(root,root);
    }
};
