//https://leetcode.com/problems/trapping-rain-water-ii/


class Solution {
public:
    map<pair<int,int>,bool> visited;
    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m=heightMap.size();
        int n=heightMap[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==0 || j==0 || i==m-1 || j==n-1)
                {
                    pq.push({heightMap[i][j],{i,j}});
                    visited[{i,j}]=true;
                }
            }
        }
        int ans=0;
        while(!pq.empty())
        {
            int val=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            for(int k=0; k<4; k++)
            {
                int x=i+dir[k][0];
                int y=j+dir[k][1];
                if(x<0||y<0||x>=m||y>=n||visited[{x,y}]==true)
                    continue;
                ans+=max(0,val-heightMap[x][y]);
                heightMap[x][y]=max(heightMap[x][y],val);
                pq.push({heightMap[x][y],{x,y}});
                visited[{x,y}]=true;
            }
        }
        return ans;
    }
};
