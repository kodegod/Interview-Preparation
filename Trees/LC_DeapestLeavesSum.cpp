//https://leetcode.com/problems/deepest-leaves-sum/

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;
        while(!q.empty())
        {
            int sz = q.size();
            sum = 0;
            while(sz--)
            {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left==NULL && curr->right==NULL)
                    sum+=curr->val;
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
            }
        }
        return sum;
    }
};
