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
