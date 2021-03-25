//https://binarysearch.com/problems/Check-if-Number-is-Perfect-Square
bool good(long long n,long long mid)
{
    long long k=mid*mid;
    if(k>=n)
        return true;
    return false;
}
bool solve(int n) {
    int start=1;
    int end=n;
    while(end>start+1)
    {
        int mid=(start+end)/2;
        if(good(n,mid))
            end=mid;
        else
            start=mid;
    }
    if(end*end==n)
        return true;
    return false;
}
