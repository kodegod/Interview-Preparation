//https://practice.geeksforgeeks.org/problems/morning-assembly3038/1

// Good Q

class Solution{
public:
    int sortingCost(int N, int arr[]){
        // code here
        map<int,int> mp;
        for(int i=0; i<N; i++)
            mp[arr[i]]=1+mp[arr[i]-1];
        int maxy=0;
        for(auto it:mp)
            maxy=max(maxy,it.second);
        return N-maxy;
    }
};
