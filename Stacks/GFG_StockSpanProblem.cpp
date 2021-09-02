//https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1

class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       stack<int> s;
       vector<int> ans(n);
       s.push(n-1);
       for(int i=n-2; i>=0; i--)
       {
           while(s.size()>0 && price[i] > price[s.top()])
           {
               ans[s.top()] = s.top() - i;
               s.pop();
           }
           s.push(i);
       }
       while(!s.empty())
       {
           ans[s.top()] = s.top() + 1;
           s.pop();
       }
       return ans;
    }
};
