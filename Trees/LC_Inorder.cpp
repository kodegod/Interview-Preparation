//https://leetcode.com/problems/binary-tree-inorder-traversal/

// Morris Traversal

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int> ans;
        while(curr!=NULL)
        {
            if(curr->left == NULL)
            {
                ans.push_back(curr->val);
                curr = curr -> right;
            }
            else
            {
                TreeNode *temp = curr->left;
                while(temp->right!= NULL && temp->right!= curr)
                    temp = temp->right;
                if(temp->right == NULL)
                {
                    temp->right = curr;
                    curr = curr->left;
                }
                else
                {
                    ans.push_back(curr->val);
                    temp->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};
