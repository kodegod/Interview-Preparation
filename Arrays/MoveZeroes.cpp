//https://leetcode.com/problems/move-zeroes/
class Solution {
public:
    void moveZeroes(vector<int>& v) {
        int n=v.size();
        int curr=0;
        int left=0;
        while(left!=n)
        {
            if(v[left]!=0)
                swap(v[left],v[curr++]);
            left++;
        }
    }
};
