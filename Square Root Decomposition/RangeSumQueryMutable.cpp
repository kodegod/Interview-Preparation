//https://leetcode.com/problems/range-sum-query-mutable/
class NumArray {
    int b;
    vector<int> block,arr;
public:
    NumArray(vector<int>& nums) {
        int n=nums.size();
        b=(int)sqrt(n)+1;
        block.resize(b+1,0);
        arr.resize(n,0);
        for(int i=0; i<n; i++)
        {
            arr[i]=nums[i];
            block[i/b]+=nums[i];
        }
    }
    
    void update(int index, int val) {
        block[index/b]-=arr[index];
        arr[index]=val;
        block[index/b]+=arr[index];
    }
    
    int sumRange(int left, int right) {
        int l=left,r=right;
        int sum=0;
        while(l%b!=0 && l<=r)
            sum+=arr[l++];
        while(l+b<=r)
        {
            sum+=block[l/b];
            l+=b;
        }
        while(l<=r)
            sum+=arr[l++];
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
