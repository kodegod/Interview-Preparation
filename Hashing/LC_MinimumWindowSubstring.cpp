//https://leetcode.com/problems/minimum-window-substring/

// VVVIP

class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        map<char,int> freq_t;
        map<char,int> freq_s;
        for(int i=0; i<m; i++)
            freq_t[t[i]]++;
        int match_count=0;
        int ans=INT_MAX;
        int i=0;
        int ans_i,ans_j;
        for(int j=0; j<n; j++)
        {
            freq_s[s[j]]++;
            if(freq_s[s[j]]<=freq_t[s[j]])
                match_count++;
            if(match_count==m)
            {
                while(match_count==m)
                {
                    freq_s[s[i]]--;
                    if(freq_s[s[i]]<freq_t[s[i]])
                        match_count--;
                    i++;
                }
                if(j-i+2<ans)
                {
                    ans=j-i+2;
                    ans_i=i-1;
                    ans_j=j;
                }
                ans=min(ans,j-i+2);
            }
        }
        if(ans==INT_MAX)
            return "";
        return s.substr(ans_i,ans_j-ans_i+1);
    }
};
