//https://leetcode.com/problems/k-closest-points-to-origin/


// O(NlogN)

class Solution {
public:
    double dist(int i,int j)
    {
        return sqrt(i*i+j*j);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>,greater<pair<double,pair<int,int>>>> pq;
        for(int i=0; i<points.size(); i++)
        {
            double val=dist(points[i][0],points[i][1]);
            pq.push({val,{points[i][0],points[i][1]}});
        }
        vector<vector<int>> ans;
        while(k--)
        {
            pair<int,int> curr=pq.top().second;
            pq.pop();
            ans.push_back({curr.first,curr.second});
        }
        return ans;     
    }
};

// O(NLogK) -> Better for Interviews

TODO
