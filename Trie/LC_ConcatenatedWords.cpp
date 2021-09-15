//https://leetcode.com/problems/concatenated-words/

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
    Node* root;
    Trie()
    {
        root = new Node('\0');
    }
    
    void insert(string word)
    {
        Node *temp = root;
        for(int i=0; i<word.size(); i++)
        {
            if(temp->children[word[i]-'a'] !=NULL)
                temp = temp->children[word[i]-'a'];
            else
            {
                temp->children[word[i]-'a'] = new Node(word[i]);
                temp = temp->children[word[i]-'a'];
            }
        }
        temp->isTerminal = true;
    }
    
    bool check(string&word,int start,int count,vector<int>&dp)
    {
        if(word.size()==start)
        {
            if(count>=2)
                return true;
            return false;
        }
        
        if(dp[start] != -1)
            return dp[start];
        
        Node *temp = root;
        for(int i=start; i<word.size(); i++)
        {
            if(temp->children[word[i]-'a'] == NULL)
                return dp[start] = false;
            temp = temp->children[word[i]-'a'];
            if(temp->isTerminal == true)
            {
                if(check(word,i+1,count+1,dp) == true)
                    return dp[start] = true;
            }
        }
        return dp[start] = false;
    }
};
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        Trie tr;
        for(auto it:words)
            tr.insert(it);
        vector<string> ans;
        for(int i=0; i<words.size(); i++)
        {
            vector<int> dp(words[i].size(),-1);
            if(tr.check(words[i],0,0,dp) == true)
                ans.push_back(words[i]);
        }
        return ans;
    }
};
