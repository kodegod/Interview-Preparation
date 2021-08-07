//https://leetcode.com/problems/long-pressed-name/

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int m = name.size();
        int n = typed.size();
        int i1=0,i2=0;
        while(i1<m && i2<n)
        {
            if(name[i1] == typed[i2])
            {
                i1++;
                i2++;
            }
            else if(i2>0 && (typed[i2] == typed[i2-1]))
            {
                i2++;
            }
            else 
                return false;
        }
        while(i2<n)
        {
            if(typed[i2] == typed[i2-1])
                i2++;
            else
                return false;
        }
        if(i1<m || i2<n)
            return false;
        return true;
    }
};
