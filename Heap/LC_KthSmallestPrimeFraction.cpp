//https://leetcode.com/problems/k-th-smallest-prime-fraction/

// Find Kth smallest element in sorted matrix (Almost same)

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>,greater<pair<double,pair<int,int>>>> pq;
        int n=arr.size();
        int last=arr[arr.size()-1];
        for(int i=0; i<n-1; i++)
            pq.push({((double)arr[i]/(double)last),{i,0}});
        int cnt=0;
        while(!pq.empty())
        {
            double val=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            cnt++;
            if(cnt==k)
                return {arr[i],arr[arr.size()-1-j]};
            if(arr.size()-j-2<=i)
                continue;
            pq.push({(double)arr[i]/(double)arr[arr.size()-j-2],{i,j+1}});
        }
        return {};
    }
};
