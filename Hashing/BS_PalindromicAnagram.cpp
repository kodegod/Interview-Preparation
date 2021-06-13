//https://binarysearch.com/problems/Palindromic-Anagram
bool solve(string s) {
    int n=s.size();
    map<char,int> mp;
    for(int i=0; i<s.size(); i++)
        mp[s[i]]++;
    int odd=0;
    for(auto it:mp)
    {
        if(it.second%2==1)
            odd++;
    }
    if(odd>1)
        return false;
    return true;
}
