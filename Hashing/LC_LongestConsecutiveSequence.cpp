//https://leetcode.com/problems/longest-consecutive-sequence/

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
            if(mp[nums[i]-1]==false && mp[nums[i]+1]==false)
                mp[nums[i]]=1;
            else if(mp[nums[i]-1]==true && mp[nums[i]+1]==false)
            {
                int endpoint=nums[i];
                int startpoint=nums[i]-mp[nums[i]-1];
                int len=endpoint-startpoint+1;
                mp[startpoint]=len;
                mp[endpoint]=len;
                ans=max(ans,len);
            }
            else if(mp[nums[i]-1]==false && mp[nums[i]+1]==true)
            {
                int startpoint=nums[i];
                int endpoint=nums[i]+mp[nums[i]+1];
                int len=endpoint-startpoint+1;
                mp[startpoint]=len;
                mp[endpoint]=len;
                ans=max(ans,len);
            }
            else
            {
                int startpoint=nums[i]-mp[nums[i]-1];
                int endpoint=nums[i]+mp[nums[i]+1];
                int len=endpoint-startpoint+1;
                mp[startpoint]=len;
                mp[endpoint]=len;
                ans=max(ans,len);
            }
        }
        return max(1,ans);
    }
};
