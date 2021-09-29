//https://practice.geeksforgeeks.org/problems/foldable-binary-tree/1

bool solve(Node* root1,Node* root2)
{
    if(root1==NULL && root2==NULL)
        return true;
    if(root1==NULL || root2==NULL)
        return false;
    return (solve(root1->left,root2->right) && solve(root1->right,root2->left));
}
bool IsFoldable(Node* root)
{
    // Your code goes here
    return solve(root,root);
}
