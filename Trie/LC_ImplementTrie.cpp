//https://leetcode.com/problems/implement-trie-prefix-tree/

class Node {
    public:
    char data;
    bool isTerminal;
    map<char,Node*> children;
    
    Node(char ch)
    {
        this->data = ch;
        isTerminal = false;
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Node* root;
    Trie() {
        this->root = new Node('\0');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* temp = this->root;
        for(int i=0; i<word.size(); i++)
        {
            if(temp->children.count(word[i]))
                temp = temp->children[word[i]];
            else
            {
                temp->children[word[i]] = new Node(word[i]);
                temp = temp->children[word[i]];
            }
        }
        temp->isTerminal = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *temp = this->root;
        for(int i=0; i<word.size(); i++)
        {
            if(temp->children.count(word[i]))
                temp = temp->children[word[i]];
            else
                return false;
        }
        return (temp->isTerminal == true);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *temp = this->root;
        for(int i=0; i<prefix.size(); i++)
        {
            if(temp->children.count(prefix[i]))
                temp = temp->children[prefix[i]];
            else
                return false;
        }
        return true;
    }
};
