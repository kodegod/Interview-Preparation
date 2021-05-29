//https://leetcode.com/problems/reconstruct-itinerary/

// Eularian Path (Hierholzer's Algorithm)


class Solution {
public:
    map<string,priority_queue<string,vector<string>,greater<string>>> g;
    vector<string> ans;
    void dfs(string src)
    {
        while(g[src].size()!=0)
        {
            string s=g[src].top();
            g[src].pop();
            dfs(s);
        }
        ans.push_back(src);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(int i=0; i<tickets.size(); i++)
            g[tickets[i][0]].push(tickets[i][1]);    
        dfs("JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
