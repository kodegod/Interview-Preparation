// https://leetcode.com/problems/alien-dictionary/

// Topological Sorting

class Solution {
public:
    map<char,vector<char>> g;
    map<char,int> indegree;
    string alienOrder(vector<string>& words) {
        int n=words.size(); 
        for(int i=0; i<n-1; i++)
        {
            int j=0;
            bool bar=false;
            while(words[i][j]==words[i+1][j])
            {
                g[words[i][j]].push_back(words[i][j]);
                if(j==words[i].size()-1)
                {
                    bar=true;
                    break;
                }
                else if(j==words[i+1].size()-1)
                    return "";
                j++;
            }
            if(bar==true)
                continue;
            g[words[i][j]].push_back(words[i+1][j]);
            indegree[words[i+1][j]]++;
        }
        for(int i=0; i<words.size(); i++)
            for(int j=0; j<words[i].size(); j++)
                if(g.find(words[i][j])==g.end() && indegree.find(words[i][j])==indegree.end())
                    indegree[words[i][j]]=0;
        queue<char> q;
        int curr=0;
        for(int i=97; i<97+26; i++)
        {
            char a=i;
            if(g.find(a)!=g.end() || indegree.find(a)!=indegree.end())
                if(indegree[a]==0)
                    q.push(a);
            if(g.find(a)!=g.end()||indegree.find(a)!=indegree.end())
                curr++;
        }
        string s;
        int cnt=0;
        while(!q.empty())
        {
            char a=q.front();
            cnt++;
            q.pop();
            s.push_back(a);
            for(auto child:g[a])
            {
                if(--indegree[child]==0)
                    q.push(child);
            }
        }
        if(cnt==curr)
        {
            if(cnt==0)
                return words[0];
            else
                return s;
        }
        return "";
    }
};
