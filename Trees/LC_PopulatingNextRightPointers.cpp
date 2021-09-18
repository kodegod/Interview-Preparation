//https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL)
            return root;
        
        Node* curr = root;
        
        while(curr!=NULL)
        {
            Node* temp = curr;
            while(temp->left!= NULL)
            {
                temp->left->next = temp->right;
                if(temp->next!=NULL)
                    temp->right->next = temp->next->left;
                if(temp->next!=NULL)
                    temp = temp->next;
                else
                    break;
            }
            curr = curr->left;
        }
        return root;
    }
};
