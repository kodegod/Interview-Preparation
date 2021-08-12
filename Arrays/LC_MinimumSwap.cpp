//https://leetcode.com/problems/maximum-swap/

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        for(int i=0; i<n; i++)
        {
            char temp = s[i+1];
            int idx = i+1;
            for(int j=i+1; j<n; j++)
            {
                if(s[j] >= temp)
                {
                    temp = s[j];
                    idx = j;
                }
            }
            if(temp > s[i])
            {
                swap(s[i],s[idx]);
                return stoi(s);
            }
        }
        return stoi(s);
    }
};
