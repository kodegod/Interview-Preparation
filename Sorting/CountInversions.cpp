// https://leetcode.com/problems/global-and-local-inversions/
class Solution {
public:
    void merge(vector<int>&v,int l1,int r1,int l2,int r2,int&inv)
    {
        int i=l1,j=l2,k=0;
        vector<int> c(r1-l1+1+r2-l2+1);
        while(i<=r1 && j<=r2)
        {
            if(v[i]<=v[j])
                c[k++]=v[i++];
            else
            {
                c[k++]=v[j++];
                inv+=r1-i+1;
            }
        }
        while(i<=r1)
            c[k++]=v[i++];
        while(j<=r2)
            c[k++]=v[j++];
        int l=0;
        for(int i=l1; i<=r2; i++)
            v[i]=c[l++];
    }
    void mergeSort(vector<int>&v,int l,int r,int&inv)
    {
        if(l==r)
            return;
        int mid=(l+r)/2;
        mergeSort(v,l,mid,inv);
        mergeSort(v,mid+1,r,inv);
        merge(v,l,mid,mid+1,r,inv);
    }
    bool isIdealPermutation(vector<int>& A) {
        int inv=0;
        int inv2=0;
        for(int i=0; i<A.size()-1; i++)
        {
            if(A[i]>A[i+1])
                inv2++;
        }
        mergeSort(A,0,A.size()-1,inv);
        cout<<inv<<" "<<inv2;
        if(inv==inv2)
            return true;
        return false;
    }
};
