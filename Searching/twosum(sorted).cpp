//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        int n=v.size();
        for(int i=0; i<n; i++)
        {
            int num1=v[i];
            int num2=target-v[i];
            int start=i+1,end=n-1;
            while(start<end)
            {
                int mid=(start+end)/2;
                if(v[mid]==num2)
                    return {i+1,mid+1};
                else if(v[mid]>num2)
                    end=mid-1;
                else
                    start=mid+1;
            }
            if(v[start]==num2)
                return{i+1,start+1};
        }
        return {};
    }
};
