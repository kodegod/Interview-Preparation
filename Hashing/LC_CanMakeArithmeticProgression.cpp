//https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        map<int,bool> mp;
        int mini=*min_element(arr.begin(),arr.end());
        int maxi=*max_element(arr.begin(),arr.end());
        if(maxi==mini)
            return true;
        int n=arr.size();
        if((maxi-mini)%(n-1)!=0)
            return false;
        int cd=(maxi-mini)/(n-1);
        for(int i=0; i<n; i++)
            mp[arr[i]]=true;
        int curr=mini;
        while(curr<=maxi)
        {
            if(mp[curr]==false)
                return false;
            curr+=cd;
        }
        return true;
    }
};
