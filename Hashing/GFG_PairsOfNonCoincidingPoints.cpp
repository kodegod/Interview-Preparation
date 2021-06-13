//https://practice.geeksforgeeks.org/problems/pairs-of-non-coinciding-points4141/1

class Solution {
  public:
    int numOfPairs(int X[], int Y[], int N) {
        // code here
        map<int,int> x,y;
        map<pair<int,int>,int> vis;
        int ans=0;
        for(int i=0; i<N; i++)
        {
            ans+=x[X[i]];
            ans+=y[Y[i]];
            ans-=2*vis[{X[i],Y[i]}];
            x[X[i]]++;
            y[Y[i]]++;
            vis[{X[i],Y[i]}]++;
        }
        return ans;
    }
};
