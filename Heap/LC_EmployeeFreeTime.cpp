//https://leetcode.com/problems/employee-free-time/

// Very good Q

/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        priority_queue<pair<pair<int,int>,pair<int,int>>,vector<pair<pair<int,int>,pair<int,int>>>,greater<pair<pair<int,int>,pair<int,int>>>> pq;
        vector<Interval> ans;
        for(int i=0; i<schedule.size(); i++)
            pq.push({{schedule[i][0].start,schedule[i][0].end},{i,0}});
        bool bar=false;
        int prev;
        while(!pq.empty())
        {
            int st=pq.top().first.first;
            int et=pq.top().first.second;
            int no=pq.top().second.first;
            int curr=pq.top().second.second;
            pq.pop();
            if(st>prev && bar==true)
            {
                Interval temp(prev,st);
                ans.push_back(temp);
            }
            bar=true;
            if(schedule[no].size()>curr+1)
                pq.push({{schedule[no][curr+1].start,schedule[no][curr+1].end},{no,curr+1}});
            prev=max(prev,et);
        }
        return ans;
    }
};
