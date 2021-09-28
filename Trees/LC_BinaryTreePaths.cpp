//https://leetcode.com/problems/binary-tree-paths/

vector<string> ans;
class Solution {
public:
    void solve(TreeNode* root,string curr)
    {
        if(root==NULL)
            return;
        string ss = curr + "->" + to_string(root->val);
        if(root->left == NULL && root->right == NULL)
        {
            ans.push_back(ss);
            return;
        }
        solve(root->left,ss);
        solve(root->right,ss);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        ans.clear();
        solve(root,"");
        for(int i=0; i<ans.size(); i++)
            ans[i]=ans[i].substr(2,ans[i].size()-2);
        return ans;
    }
};
