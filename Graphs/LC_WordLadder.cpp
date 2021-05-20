//https://leetcode.com/problems/word-ladder/
class Solution {
public:
    map<string,vector<string>> g;
    map<string,bool> visited;
    map<string,int> level;
    int bfs(string beginWord, string endWord)
    {
        queue<string> q;
        q.push(beginWord);
        level[beginWord]=1;
        visited[beginWord]=true;
        while(!q.empty())
        {
            string node=q.front();
            q.pop();
            if(node==endWord)
                return level[beginWord];
            cout<<node<<" ";
            for(auto it:g[node])
            {
                if(!visited[it])
                {
                    q.push(it);
                    visited[it]=true;
                    level[it]=level[node]+1;
                    if(it==endWord)
                        return level[it];
                }
            }
        }
        return INT_MAX;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool bar=true;
        for(int i=0; i<wordList.size(); i++)
        {
            if(wordList[i]==endWord)
            {
                bar=false;
                break;
            }
        }
        if(bar==true)
            return 0;
        for(int i=0; i<wordList.size(); i++)
        {
            for(int j=i+1; j<wordList.size(); j++)
            {
                int diff=0;
                for(int k=0; k<wordList[i].size(); k++)
                {
                    if(wordList[i][k]!=wordList[j][k])
                        diff++;
                }
                if(diff==1)
                {
                    g[wordList[i]].push_back(wordList[j]);
                    g[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        int ans=INT_MAX;
        for(int i=0; i<wordList.size(); i++)
        {
            int diff=0;
            for(int k=0; k<wordList[i].size(); k++)
            {
                if(wordList[i][k]!=beginWord[k])
                    diff++;
            }
            if(diff==1)
            {
                level.clear();
                visited.clear();
                ans=min(ans,bfs(wordList[i],endWord));
            }
        }
        if(ans==INT_MAX)
            return 0;
        return ans+1;
    }
};
