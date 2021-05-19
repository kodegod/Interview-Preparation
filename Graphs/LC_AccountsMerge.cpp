//https://leetcode.com/problems/accounts-merge/
class Solution {
public:
    map<string,string> par;
    map<string,int> sz;
    map<string,int> owner;
    map<int,vector<string>> ans;
    map<int,string> key;
    string get_root(string u)
    {
        if(par[u]==u)
            return u;
        return par[u]=get_root(par[u]);
    }
    
    void merge(string u,string v)
    {
        string a=get_root(u);
        string b=get_root(v);
        if(a==b)
            return;
        if(sz[b]>sz[a])
            swap(a,b);
        par[b]=a;
        sz[a]+=sz[b];
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        for(int i=0; i<n; i++)
        { 
            key[i]=accounts[i][0];
            for(int j=1; j<accounts[i].size(); j++)
            {
                par[accounts[i][j]]=accounts[i][j];
                owner[accounts[i][j]]=i;
                sz[accounts[i][j]]=1;
            }
        }
        for(int i=0; i<n; i++)
        { 
            for(int j=1; j<accounts[i].size(); j++)
                merge(accounts[i][1],accounts[i][j]);
            
        }
        for(int i=0; i<n; i++)
        {
            for(int j=1; j<accounts[i].size(); j++)
            {
                int ow=owner[get_root(accounts[i][j])];
                ans[ow].push_back(accounts[i][j]);
            }
        }
        vector<vector<string>> sol;
        for(auto it:ans)
        {
            vector<string> vv;
            string temp=key[it.first];
            vv.push_back(temp);
            sort(it.second.begin(),it.second.end());
            map<string,bool> visited;
            for(auto ip:it.second)
            {
                if(!visited[ip])
                {
                    visited[ip]=true;
                    vv.push_back(ip);
                }
            }
            sol.push_back(vv);
        }
        return sol;
    }
};
