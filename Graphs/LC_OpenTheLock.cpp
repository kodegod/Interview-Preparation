//https://leetcode.com/problems/open-the-lock/

// BFS

class Solution {
public:
    map<string,bool> visited;
    map<string,bool> dead;
    int bfs(string s,vector<string>& deadends,string target)
    {
        queue<string> q;
        q.push(s);
        visited[s]=true;
        int k=0;
        while(!q.empty())
        {
            int len=q.size();
            while(len--)
            {
                string curr=q.front();
                q.pop();
                if(curr==target)
                    return k;
                for(int i=0; i<4; i++)
                {
                    string temp=curr;
                    if(curr[i]=='9')
                        temp[i]='0';
                    else
                        temp[i]=curr[i]+1;
                    if(!visited[temp] && dead[temp]==false)
                    {
                        visited[temp]=true;
                        q.push(temp);
                    }
                    temp=curr;
                    if(curr[i]=='0')
                        temp[i]='9';
                    else
                        temp[i]=curr[i]-1;
                    if(!visited[temp] && dead[temp]==false)
                    {
                        visited[temp]=true;
                        q.push(temp);
                    }
                }
            }
            k++;
        }
        return -1;
    }
    int openLock(vector<string>& deadends, string target) {
        for(int i=0; i<deadends.size(); i++)
            dead[deadends[i]]=true;
        if(dead["0000"]==true)
            return -1;
        return bfs("0000",deadends,target);
    }
};
