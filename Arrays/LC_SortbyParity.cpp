//https://leetcode.com/problems/sort-array-by-parity/


class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int n=A.size();
        int curr=0;
        int left=0;
        while(left!=n)
        {
            if(A[left]%2==0)
                swap(A[left],A[curr++]);
            left++;
        }
        return A;
    }
};
