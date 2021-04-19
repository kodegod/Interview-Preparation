//https://leetcode.com/problems/longest-increasing-subsequence/
class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int> sols;
        for (int i = 0; i < n; i++)
        {
            if (sols.size() == 0 || arr[i] > sols.back())
                sols.push_back(arr[i]);
            else
            {
                auto it = lower_bound(sols.begin(), sols.end(), arr[i]);
                *it = arr[i];
            }
        }
        return sols.size();
    }
};

// O(NlogN)
