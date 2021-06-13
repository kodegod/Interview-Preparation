//https://binarysearch.com/problems/Unique-Occurrences
bool solve(vector<int>& nums) {
    map<int,int> mp;
    for(auto it:nums)
        mp[it]++;
    bool bar=true;
    map<int,int> m2;
    for(auto it:mp)
        m2[it.second]++;
    for(auto it:m2)
    {
        if(it.second>1)
        {
            bar=false;
            break;
        }
    }
    return bar;
}
