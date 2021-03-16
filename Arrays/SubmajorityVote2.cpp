//https://binarysearch.com/room/DP-Experts-BKy8Dy3eqK?questionsetIndex=2
vector<int> solve(vector<int>& nums) {
    int num1=-1,num2=-1;
    int c1=0,c2=0;
    int n=nums.size();
    for(int i=0; i<nums.size(); i++)
    {
        if(nums[i]==num1)
            c1++;
        else if(nums[i]==num2)
            c2++;
        else if(c1==0)
        {
            c1++;
            num1=nums[i];
        }
        else if(c2==0)
        {
            c2++;
            num2=nums[i];
        }
        else
        {
            c1--;
            c2--;
        }
    }
    c1=0,c2=0;
    for(auto it:nums)
    {
        if(it==num1)
            c1++;
        if(it==num2)
            c2++;
    }
    vector<int> v;
    if(c1>(n/3))
        v.push_back(num1);
    if(c2>(n/3))
        v.push_back(num2);
    sort(v.begin(),v.end());
    return v;
}
