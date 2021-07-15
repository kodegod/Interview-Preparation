//https://practice.geeksforgeeks.org/problems/box-stacking/1#

// Very Good Q - LIS 

class Solution{
    public:
    int maxHeight(int height[],int width[],int length[],int n)
    {
        //Your code here
        vector<pair<vector<int>,int>> v;
        for(int i=0; i<n; i++)
        {
            v.push_back({{height[i],width[i]},length[i]});
            v.push_back({{width[i],height[i]},length[i]});
            v.push_back({{height[i],length[i]},width[i]});
            v.push_back({{length[i],height[i]},width[i]});
            v.push_back({{length[i],width[i]},height[i]});
            v.push_back({{width[i],length[i]},height[i]});
        }
        sort(v.begin(),v.end());
        vector<int> dp(v.size(),0);
        for(int i=0; i<v.size(); i++)
            dp[i]=v[i].second;
        for(int i=1; i<v.size(); i++)
        {
            int ans=0;
            for(int j=0; j<i; j++)
            {
                if(v[i].first[0] > v[j].first[0] && v[i].first[1] > v[j].first[1])
                    ans=max(ans,dp[j]);
            }
            dp[i]+=ans;
        }
        return *max_element(dp.begin(),dp.end());
    }
};

int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int n;
        cin>>n;
        
    
        int A[105],B[105],C[105];
        for(int i = 0; i < n; i++)cin >> A[i];
        for(int j = 0; j < n; j++)cin >> B[j];
        for(int k = 0; k < n; k++)cin >> C[k];
        Solution ob;
        cout<<ob.maxHeight(A,B,C,n)<<endl;
    }
	
	return 0;
}
	  // } Driver Code Ends
