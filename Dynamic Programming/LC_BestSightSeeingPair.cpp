//https://leetcode.com/problems/best-sightseeing-pair/

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int curr_best = values[0];
        int curr_idx = 0;
        int ans = 0;
        for(int i=1; i<n; i++)
        {
            ans = max(ans,curr_best+values[i]-i+curr_idx);
            if(values[i] + i - curr_idx >= curr_best)
            {
                curr_best = values[i];
                curr_idx = i;
            }
        }
        return ans;
    }
};
