//https://leetcode.com/problems/find-all-anagrams-in-a-string/


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        int m=p.size();
        map<char,int> m1,m2;
        for(int i=0; i<m; i++)
            m1[p[i]]++;
        int match_count=0;
        vector<int> ans;
        for(int i=0; i<n; i++)
        {
            if(i-m>=0)
            {
                m2[s[i-m]]--;
                if(m2[s[i-m]]<m1[s[i-m]])
                    match_count--;
            }
            m2[s[i]]++;
            if(m2[s[i]]<=m1[s[i]])
                match_count++;
            if(match_count==m)
                ans.push_back(i-m+1);
        }
        return ans;
    }
};
