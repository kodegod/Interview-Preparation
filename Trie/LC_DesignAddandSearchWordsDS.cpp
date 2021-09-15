//https://leetcode.com/problems/design-add-and-search-words-data-structure/

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

class WordDictionary {
public:
    /** Initialize your data structure here. */
    Node *root;
    WordDictionary() {
        root = new Node('\0');
    }
    
    void addWord(string word) {
        Node *temp = root;
        for(int i=0; i<word.size(); i++)
        {
            if(temp->children[word[i]-'a']!=NULL)
                temp = temp->children[word[i]-'a'];
            else
            {
                temp->children[word[i]-'a'] = new Node(word[i]);
                temp = temp->children[word[i]-'a'];
            }
        }
        temp->isTerminal = true;
    }
    
    bool searchXD(string word, Node *temp) {
        if(word.size() == 0)
            return (temp->isTerminal == true);
        bool bar = false;
        for(int i=0; i<word.size(); i++)
        {
            if(word[i] == '.')
            {
                for(auto it: temp->children)
                {
                    if(it!=NULL)
                    {
                        string news = word.substr(i+1);
                        if(searchXD(news,it) == true)
                            return true;
                    }
                }
                return false;
            }
            else if(temp->children[word[i]-'a']!=NULL)
                temp = temp->children[word[i]-'a'];
            else
                return false;
        }
        return (temp->isTerminal == true);
    }
    
    bool search(string word)
    {
        return searchXD(word,root);
    }
        
};
