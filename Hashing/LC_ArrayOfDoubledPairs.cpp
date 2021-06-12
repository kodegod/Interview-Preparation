//https://leetcode.com/problems/array-of-doubled-pairs/


class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int n=arr.size();
        map<int,int> mp;
        for(int i=0; i<n; i++)
            mp[arr[i]]++;
        sort(arr.begin(),arr.end());
        for(int i=0; i<n; i++)
        {
            if(mp[arr[i]]==0)
                continue;
            if(arr[i]<0)
            {
                if(abs(arr[i])%2==1)
                    return false;
                int sec=arr[i]/2;
                if(mp[sec]==0)
                    return false;
                mp[sec]--;
                mp[arr[i]]--;
            }
            else
            {
                int sec=arr[i]*2;
                if(mp[sec]==0)
                    return false;
                mp[sec]--;
                mp[arr[i]]--;
            }

        }
        return true;
    }
};
