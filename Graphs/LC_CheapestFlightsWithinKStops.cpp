//https://leetcode.com/problems/cheapest-flights-within-k-stops/

// Bellman Ford 2D

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> ans(n,vector<int> (k+2,INT_MAX));
        for(int i=0; i<=k+1; i++)
            ans[src][i]=0;
        for(int i=1; i<=k+1; i++)
        {
            for(int j=0; j<flights.size(); j++)
            {
                if(ans[flights[j][0]][i-1]==INT_MAX)
                    continue;
                ans[flights[j][1]][i]=min(ans[flights[j][1]][i],ans[flights[j][0]][i-1]+flights[j][2]);
            }
        }
        if(ans[dst][k+1]==INT_MAX)
            return -1;
        return ans[dst][k+1];
    }
};

// Dijkstra variation (better)

class Solution {
public:
    map<int,vector<pair<int,int>>> g;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        for(int i=0; i<flights.size(); i++)
            g[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        vector<int> ans(n,INT_MAX);
        queue<pair<int,int>> q;
        q.push({src,0});
        ans[src]=0;
        k++;
        while(!q.empty())
        {
            if(k==0)
                break;
            int len=q.size();
            while(len--)
            {
                pair<int,int> curr=q.front();
                q.pop();
                for(auto it:g[curr.first])
                {
                    if(ans[it.first]>it.second + curr.second)
                    {
                        ans[it.first]=curr.second+it.second;
                        q.push({it.first,ans[it.first]});
                    }
                }
            }
            k--;
        }
        return ans[dst]==INT_MAX?-1:ans[dst];
    }
};
