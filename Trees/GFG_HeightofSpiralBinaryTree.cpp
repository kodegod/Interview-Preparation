//https://practice.geeksforgeeks.org/problems/height-of-spiral-tree/1

int findTreeHeight(Node* root)
{
	// Code here
	if(root==NULL)
	    return 0;
	    
	if(root->left && root->right && root->left->right == root && root->right->left == root)
	return 1; // leaf node
	
	return 1 + max(findTreeHeight(root->left),findTreeHeight(root->right));
}
