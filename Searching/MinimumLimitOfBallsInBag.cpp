
//https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/
class Solution {
public:
    int minimumSize(vector<int>& v, int k) {
        int n=v.size();
        int maxy = *max_element(v.begin(), v.end());
        int start = 1;
        int end = maxy;
        while (start < end)
        {
            int maxans = (start + end) / 2;
            int count = 0;
            for (auto it : v)
                count += (it - 1) / maxans;
            if (count > k)
                start = maxans + 1;
            else
                end = maxans;
        }
        return start;
    }
};
