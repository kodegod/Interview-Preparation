//https://leetcode.com/problems/maximal-rectangle/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nsl(n,n);
        vector<int> nsr(n,-1);
        stack<int> s;
        s.push(0);
        for(int i=1; i<n; i++)
        {
            while(s.size()>0 && heights[s.top()] > heights[i])
            {
                nsl[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty())
            s.pop();
        s.push(n-1);
        for(int i=n-2; i>=0; i--)
        {
            while(s.size()>0 && heights[s.top()] > heights[i])
            {
                nsr[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        int ans = INT_MIN;
        for(int i=0; i<n; i++)
            ans = max(ans, heights[i]*(nsl[i] - nsr[i] - 1));
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = INT_MIN;
        int m = matrix.size();
        if(m==0)
            return 0;
        int n = matrix[0].size();
        if(n==0)
            return 0;
        vector<int> v(n,0);
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j] == '1')
                    v[j]+=1;
                else
                    v[j]=0;
            }
            ans = max(ans,largestRectangleArea(v));
        }
        return ans;
    }
};
