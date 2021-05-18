//https://leetcode.com/problems/evaluate-division/submissions/
class Solution {
public:
    map<string,vector<pair<string,double>>> g;    
    double bfs(string a,string b)
    {       
        map<string,bool> visited;
        queue<string> q;
        q.push(a);
        visited[a]=true;
        map<string,double> ans;
        ans[a]=1;
        while(!q.empty())
        {
            string temp=q.front();
            q.pop();
            if(temp==b && g.find(temp)!=g.end())
                return ans[temp];
            for(auto child:g[temp])
            {
                if(!visited[child.first])
                {
                    ans[child.first]=ans[temp]*child.second;
                    q.push(child.first);
                    if(child.first==b)
                        return ans[child.first];
                    visited[child.first]=true;
                }
            }
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        for(int i=0; i<equations.size(); i++)
        {
            string x=equations[i][0];
            string y=equations[i][1];
            g[x].push_back({y,values[i]});
            g[y].push_back({x,(1/values[i])});
        }
        for(int i=0; i<queries.size(); i++)
        {     
            double curr=bfs(queries[i][0],queries[i][1]);
            ans.push_back(curr);
        }
        return ans;
    }
};
