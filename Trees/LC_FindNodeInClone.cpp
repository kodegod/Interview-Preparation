//https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*> q;
        q.push(cloned);
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->val == target->val)
                    return curr;
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
            }
        }
        return original;
    }
};
