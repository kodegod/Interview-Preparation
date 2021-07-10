//https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

// BS on answer

class Solution {
public:
    bool good(vector<int>& weights, int days,int mid)
    {
        int cnt=0;
        int curr_wt=0;
        for(int i=0; i<weights.size(); i++)
        {
            curr_wt+=weights[i];
            if(curr_wt>mid)
            {
                cnt++;
                curr_wt=0;
                i--;
            }
        }
        if(cnt+1<=days)
            return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int start=*max_element(weights.begin(),weights.end());
        int end=0;
        for(int i=0; i<n; i++)
            end+=weights[i];
        while(start+1<end)
        {
            int mid=start+(end-start)/2;
            if(good(weights,days,mid))
                end=mid;
            else
                start=mid;
        }
        if(good(weights,days,start)==true)
            return start;
        return end;
    }
};
