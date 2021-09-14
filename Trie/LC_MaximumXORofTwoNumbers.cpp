//https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

// Binary Trie

class Node {
    public:
    char data;
    Node* left;
    Node* right;
    Node(char ch)
    {
        data = ch;
        left = NULL;
        right = NULL;
    }
};

class Trie {
    public:
    Node* root;
    Trie(){
        root = new Node('\0');
    }
    void insert(string word)
    {
        Node *temp = root;
        for(int i=0; i<word.size(); i++)
        {
            if(word[i] == '0')
            {
                if(temp->left!=NULL)
                    temp = temp->left;
                else
                {
                    temp->left = new Node(word[i]);
                    temp = temp->left;
                }
            }
            else
            {
                if(temp->right!=NULL)
                    temp = temp->right;
                else
                {
                    temp->right = new Node(word[i]);
                    temp = temp->right;
                }
            }
        }
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie tr;
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            string s = bitset<32>(nums[i]).to_string();
            tr.insert(s);
        }
        for(int i=0; i<n; i++)
        {
            string s = bitset<32>(nums[i]).to_string();
            Node *temp = tr.root;
            int curr = 0;
            for(int j=0; j<s.size(); j++)
            {
                if(s[j] == '0')
                {
                    if(temp->right != NULL)
                    {
                        curr += 1<<(31-j);
                        temp = temp->right;
                    }
                    else
                        temp = temp->left;
                }
                else
                {
                    if(temp->left != NULL)
                    {
                        curr += 1<<(31-j);
                        temp = temp->left;
                    }
                    else
                        temp = temp->right;
                }
            }
            ans = max(ans,curr);
        }
        return ans;
    }
};
