//https://leetcode.com/problems/median-of-two-sorted-arrays/

// Very imp Q

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size()<nums1.size())
            swap(nums1,nums2);
        int m=nums1.size();
        int n=nums2.size();
        int on_left=(m+n+1)/2;
        if(m==0)
        {
            if(n%2==1)
                return nums2[on_left-1];
            else
                return (double)(nums2[on_left-1]+nums2[on_left])/2;
        }
        if(n==0)
        {
            if(m%2==1)
                return nums1[on_left-1];
            else
                return (double)(nums1[on_left-1]+nums1[on_left])/2;
        }
        int start=0;
        int end=m;
        while(start<=end)
        {
            int mid1=(start)+(end-start)/2;
            int mid2=on_left-mid1;
            if((mid2==0 || mid1==m || nums2[mid2-1] <= nums1[mid1]) && (mid1==0 || mid2==n || nums1[mid1-1] <= nums2[mid2]))
            {
                int a=INT_MIN,b=INT_MAX;
                if(mid1!=0)
                    a=max(a,nums1[mid1-1]);
                if(mid2!=0)
                    a=max(a,nums2[mid2-1]);
                if(mid1!=m)
                    b=min(b,nums1[mid1]);
                if(mid2!=n)
                    b=min(b,nums2[mid2]);
                if((m+n)%2==0)
                    return (double)(a+b)/(double)2;
                else
                    return a;
            }
            else if((mid1==0 || mid2==n || nums1[mid1-1]<= nums2[mid2]) && (mid2==0 || mid1==m || nums2[mid2-1] >= nums1[mid1]))
            {
                start=mid1+1;
                continue;
            }
            else
            {
                end=mid1-1;
                continue;
            }
        }
        return 0;
    }
};
