//https://leetcode.com/problems/find-in-mountain-array/
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &v) {
        int n=v.length();
        int start=1;
        int end=n-1;
        int peak=0;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(v.get(mid)>v.get(mid-1)&&v.get(mid)>v.get(mid+1))
            {
                peak=mid;
                break;
            }
            else if(v.get(mid+1)>v.get(mid))
                start=mid+1;
            else
                end=mid-1;
        }
        start=0;
        end=peak;
        while(start<end)
        {
            int mid=(start+end)/2;
            if(v.get(mid)==target)
                return mid;
            else if(v.get(mid)>=target)
                end=mid;
            else
                start=mid+1;
        }
        if(v.get(start)==target)
            return start;
        start=n-1;
        end=peak+1;
        while(start>end)
        {
            int mid=(start+end+1)/2;
            if(v.get(mid)==target)
                return mid;
            else if(v.get(mid)>=target)
                end=mid;
            else
                start=mid-1;
        }
        if(v.get(start)==target)
            return start;
        return -1;
    }
};
