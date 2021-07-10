// https://www.interviewbit.com/problems/painters-partition-problem/

// BS on answer

bool good(int A, int B, vector<int> &C,int mid)
{
    int cnt=0;
    long long curr_time=0;
    for(int i=0; i<C.size(); i++)
    {
        curr_time+=(C[i]);
        if(curr_time>mid)
        {
            cnt++;
            curr_time=0;
            i--;
        }
    }
    cnt++;
    if(cnt<=A)
        return true;
    return false;
}
int Solution::paint(int A, int B, vector<int> &C) {
    int n=C.size();
    long long start=0,end=0;
    for(int i=0; i<n; i++)
    {
        start=max(start,(long long)(C[i]));
        end+=(C[i]);
    }
    while(start+1<end)
    {
        long long mid=start+(end-start)/2;
        if(good(A,B,C,mid))
            end=mid;
        else
            start=mid;
    }
    if(good(A,B,C,start)==true)
        return (start*B)%10000003;
    return (end*B)%10000003;
}
