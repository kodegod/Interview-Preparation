//https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

// Good Q

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m=matrix.size();
        int n=matrix[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        for(int i=0; i<m; i++)
            pq.push({matrix[i][0],{i,0}});
        int cnt=0;
        while(!pq.empty())
        {
            int val=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            cnt++;
            if(cnt==k)
                return val;
            if(j==n-1)
                continue;
            pq.push({matrix[i][j+1],{i,j+1}});
        }
        return 0;
    }
};
