//https://leetcode.com/problems/implement-trie-prefix-tree/

class Node {
public:
    char data;
    bool isTerminal;
    Node* children[26];
    
    Node(char ch)
    {
        data = ch;
        isTerminal = false;
        for(int i=0; i<26; i++)
            children[i] = NULL;
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Node* root;
    Trie() {
        root = new Node('\0');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* temp = root;
        for(int i=0; i<word.size(); i++)
        {
            if(temp->children[word[i]-'a'] != NULL)
                temp = temp->children[word[i]-'a'];
            else
            {
                temp->children[word[i]-'a'] = new Node(word[i]);
                temp = temp->children[word[i]-'a'];
            }
        }
        temp->isTerminal = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *temp = root;
        for(int i=0; i<word.size(); i++)
        {
            if(temp->children[word[i]-'a'] != NULL)
                temp = temp->children[word[i]-'a'];
            else
                return false;
        }
        return (temp->isTerminal == true);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *temp = root;
        for(int i=0; i<prefix.size(); i++)
        {
            if(temp->children[prefix[i]-'a'] != NULL)
                temp = temp->children[prefix[i]-'a'];
            else
                return false;
        }
        return true;
    }
};
