//https://leetcode.com/problems/minimum-number-of-refueling-stops/



class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        sort(stations.begin(),stations.end());
        priority_queue<int> pq;
        int currfuel=startFuel;
        int curr=0;
        stations.push_back({target,0});
        for(int i=0; i<stations.size(); i++)
        {
            int dist_to_cover=stations[i][0]-curr;
            if(currfuel<dist_to_cover)
            {
                while(currfuel<dist_to_cover)
                {
                    if(pq.empty())
                        return -1;
                    currfuel+=pq.top();
                    pq.pop();
                }
            }
            pq.push(stations[i][1]);
            currfuel-=dist_to_cover;
            curr=stations[i][0];
        }
        int k=pq.size();
        return stations.size()-k;
    }
};
