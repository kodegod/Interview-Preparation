//https://leetcode.com/problems/container-with-most-water/


class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i=0;
        int j=n-1;
        int ans = 0;
        while(i<j)
        {
            int a = min(height[i],height[j]);
            int b = j-i;
            ans = max(ans,a*b);
            if(height[i]>=height[j])
                j--;
            else
                i++;
        }
        return ans;
    }
};
