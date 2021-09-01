//https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

class Solution {
public:
    map<long long,vector<pair<long long,long long>>> g;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<long long> dist(n,1e18);
        vector<long long> ways(n,0);
        long long m = roads.size();
        for(int i=0; i<m; i++)
        {
            g[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            g[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        pq.push({0,0});
        ways[0] = 1;
        while(!pq.empty())
        {
            long long curr_dist = pq.top().first;
            long long curr_node = pq.top().second;
            pq.pop();
            for(auto child:g[curr_node])
            {
                if(dist[child.first] > curr_dist + child.second)
                {
                    dist[child.first] = curr_dist + child.second;
                    ways[child.first] = ways[curr_node];
                    pq.push({dist[child.first],child.first});
                }
                else if(dist[child.first] == curr_dist + child.second)
                    ways[child.first] = (ways[child.first] + ways[curr_node])%1000000007;
            }
        }
        return ways[n-1];
    }
};
