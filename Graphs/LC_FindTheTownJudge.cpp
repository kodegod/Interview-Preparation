//https://leetcode.com/problems/find-the-town-judge/
class Solution {
public:
    map<int,vector<int>> indegree,outdegree;
    int findJudge(int n, vector<vector<int>>& trust) {
        for(int i=0; i<trust.size(); i++)
        {
            outdegree[trust[i][0]].push_back(trust[i][1]);
            indegree[trust[i][1]].push_back(trust[i][0]);
        }
        int judge=-1;
        for(int i=1; i<=n; i++)
        {
            if(indegree[i].size()==n-1)
                judge=i;
        }
        if(outdegree[judge].size()==0)
            return judge;
        return -1;
    }
};
