//

class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b)
    {
        return (a[0] < b[0]) || (a[0] == b[0] && a[1] > b[1]);
    }
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> v;
        for(int i=0; i<buildings.size(); i++)
        {
            v.push_back({buildings[i][0],buildings[i][2]});
            v.push_back({buildings[i][1],-buildings[i][2]});
        }
        sort(v.begin(),v.end(),compare);
        multiset<int> pq;
        vector<vector<int>> ans;
        pq.insert(0);
        int curr_height=0;
        for(int i=0; i<v.size(); i++)
        {
            if(v[i][1]>=0)      // up
            {
                pq.insert(v[i][1]);
                if(v[i][1]>curr_height)
                {
                    curr_height=*pq.rbegin();
                    ans.push_back({v[i][0],curr_height});
                }
            }
            else             // down
            {
                pq.erase(pq.find(-v[i][1]));
                if(abs(v[i][1])==curr_height)
                {
                    curr_height=*pq.rbegin();
                    ans.push_back({v[i][0],curr_height});
                }
            }
        }
        for(int i=0; i<ans.size()-1; i++)
        {
            if(ans[i][0]==ans[i+1][0])
            {
                ans.erase(ans.begin()+i);
                i--;
            }
        }
        for(int i=0; i<ans.size()-1; i++)
        {
            if(ans[i][1]==ans[i+1][1])
            {
                ans.erase(ans.begin()+i+1);
                i--;
            }
        }
        return ans;
    }
};
