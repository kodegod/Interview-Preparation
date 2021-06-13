//https://leetcode.com/problems/grid-illumination/

class Solution {
public:
    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        map<int,int> row,col,dia1,dia2;
        map<pair<int,int>,int> lamp;
        for(int i=0; i<lamps.size(); i++)
        {
            if(lamp[{lamps[i][0],lamps[i][1]}]==true)
                continue;
            lamp[{lamps[i][0],lamps[i][1]}]=true;
            row[lamps[i][0]]++;
            col[lamps[i][1]]++;
            dia1[lamps[i][0]+lamps[i][1]]++;
            dia2[lamps[i][0]-lamps[i][1]]++;
        }
        vector<int> ans;
        for(int i=0; i<queries.size(); i++)
        {
            int a=queries[i][0];
            int b=queries[i][1];
            if(row[a]>0 || col[b]>0 || dia1[a+b]>0 || dia2[a-b]>0)
            {
                ans.push_back(1);
                if(lamp[{a,b}]==true)
                {
                    row[a]--;
                    col[b]--;
                    dia1[a+b]--;
                    dia2[a-b]--;
                    lamp[{a,b}]=false;
                }
                for(int k=0; k<8; k++)
                {
                    int x=queries[i][0]+dir[k][0];
                    int y=queries[i][1]+dir[k][1];
                    if(x<0||y<0||x>=n||y>=n)
                        continue;
                    if(lamp[{x,y}]==true)
                    {
                        row[x]--;
                        col[y]--;
                        dia1[x+y]--;
                        dia2[x-y]--;
                        lamp[{x,y}]=false;
                    }
                }
            }
            else
                ans.push_back(0);
        }
        return ans;
    }
};
