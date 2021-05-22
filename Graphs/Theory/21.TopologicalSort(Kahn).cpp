class Solution {
public:
    vector<int> indegree;
    map<int,vector<int>> g;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prereq){
        int n=numCourses;
        indegree.resize(n,0);
        for(int i=0; i<prereq.size(); i++)
        {
            indegree[prereq[i][0]]++;
            g[prereq[i][1]].push_back(prereq[i][0]);
        }
        queue<int> q;
        for(int i=0; i<n; i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        vector<int> ans;
        int cnt=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            cnt++;
            ans.push_back(node);
            for(auto it:g[node])
            {
                if(--indegree[it]==0)
                    q.push(it);
            }
        }
        if(cnt!=n)
            return {};
        return ans;
    }
};
