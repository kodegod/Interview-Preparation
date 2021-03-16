//VVVGOOD Q
//https://binarysearch.com/problems/Skydivers
int solves(vector<int>& nums, int k,int n)
{
    int start=*max_element(nums.begin(),nums.end());
    int end=0;
    for(auto it:nums)
        end+=it;
    while(start<end)
    {
        int mid=(start+end)/2;
        int g=0;
        int cursum=0;
        for(int i=0; i<n; i++)
        {
            cursum+=nums[i];
            if(cursum>mid)
            {
                cursum=0;
                g++;
                i--;
            }
        }
        if(cursum>0)
            g++;
        if(g>k)
            start=mid+1;
        else if(g<=k)
            end=mid;
    }
    return end;
}
int solve(vector<int>& nums, int k) {
    int n=nums.size();
    return solves(nums,k,n);
}
