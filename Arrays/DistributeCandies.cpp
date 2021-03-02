class Solution {
public:
    int distributeCandies(vector<int>& num) {
        map<int,int> mp;
        int n=num.size();
        for(int i=0; i<n; i++)
                mp[num[i]]++;
        int x=mp.size();
        if(x>=n/2)
            return n/2;
        else
            return x;
    }
};
