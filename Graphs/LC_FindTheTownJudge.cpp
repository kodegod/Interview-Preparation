//https://leetcode.com/problems/find-the-town-judge/
class Solution {
public:
    vector<int> outdegree,indegree;
    int findJudge(int n, vector<vector<int>>& trust) {
        indegree.resize(n+1,0);
        outdegree.resize(n+1,0);
        for(int i=0; i<trust.size(); i++)
        {
            outdegree[trust[i][0]]++;
            indegree[trust[i][1]]++;
        }
        int judge=-1;
        for(int i=1; i<=n; i++)
        {
            if(indegree[i]==n-1 && outdegree[i]==0)
                return i;
        }
        return -1;
    }
};
