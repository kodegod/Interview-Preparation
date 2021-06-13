//https://leetcode.com/problems/longest-consecutive-sequence/


// Good Q

class Solution {
public:
    map<int,bool> visited;
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        int ans=0;
        map<int,int> mp;
        for(int i=0; i<n; i++)
        {
            if(visited[nums[i]]==true)
                continue;
            visited[nums[i]]=true;
            int startpoint=nums[i];
            int endpoint=nums[i];
            if(mp[nums[i]-1]>0)
                startpoint=nums[i]-mp[nums[i]-1];
            if(mp[nums[i]+1]>0)
                endpoint=nums[i]+mp[nums[i]+1];
            int len=(endpoint-startpoint+1);
            mp[startpoint]=len;
            mp[endpoint]=len;
            ans=max(ans,len);
        }
        return max(1,ans);
    }
};
