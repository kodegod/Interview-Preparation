//https://www.geeksforgeeks.org/next-greater-element/

class Solution
{
    public:
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        stack<long long> s;
        s.push(0);
        vector<long long> ans(n);
        for(int i=1; i<n; i++)
        {
            while(s.size() > 0 && arr[i] > arr[s.top()])
            {
                ans[s.top()] = arr[i];
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty())
        {
            ans[s.top()] = -1;
            s.pop();
        }
        return ans;
    }
};
