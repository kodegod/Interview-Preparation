//https://leetcode.com/problems/gas-station/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curr = 0;
        int sum = 0;
        int ans = 0;
        for(int i=0; i<gas.size(); i++)
        {
            sum += gas[i] - cost[i];
            curr += gas[i] - cost[i] ;
            if(sum < 0)
            {
                ans = i+1;
                sum = 0;
            }
        }
        return (curr>=0)?(ans%gas.size()):-1;
    }
};
