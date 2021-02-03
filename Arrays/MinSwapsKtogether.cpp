int minSwap(int *arr, int n, int k) {
    int count=0;
    for(int i=0; i<n; i++)
    {
        if(arr[i]<=k)
            count++;
    }
    int ans=0;
    int bomb=0;
    for(int i=0; i<count; i++)
    {
        if(arr[i]<=k)
            ans++;
    }
    bomb=ans;
    for(int i=count; i<n; i++)
    {
        if(arr[i-count]<=k)
            ans--;
        if(arr[i]<=k)
            ans++;
        bomb=max(bomb,ans);
    }
    return count-bomb;
}
