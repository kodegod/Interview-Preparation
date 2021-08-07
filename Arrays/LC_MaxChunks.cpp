//https://leetcode.com/problems/max-chunks-to-make-sorted/

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> pmax(n,0);
        pmax[0] = arr[0];
        for(int i=1; i<n; i++)
            pmax[i] = max(pmax[i-1],arr[i]);
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            if(pmax[i] == i)
                ans++;
        }
        return ans;
    }
};
