//https://binarysearch.com/problems/K-Unique-String
int solve(string s, int k) {
    map<char,int> mp;
    for(int i=0; i<s.size(); i++)
        mp[s[i]]++;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(auto it:mp)
        pq.push(it.second);
    int x=mp.size();
    int ans=0;
    for(int i=0; i<x-k; i++)
    {
        ans+=pq.top();
        pq.pop();
    }
    return ans;
}
