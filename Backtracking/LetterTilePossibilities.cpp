class Solution {
public:
    map<string,bool> mp;
    map<string,bool> ms;
    void subsets(string ip,string op,int&count)
    {
        if(op.size()==0)
        {
            if(ms[ip]==false)
            {
                ms[ip]=true;
                count++;
            }
            return;
        }
        string temp=ip;
        temp.push_back(op[0]);
        op.erase(op.begin());
        subsets(ip,op,count);
        subsets(temp,op,count);
    }
    void permute(string&tiles,int i,vector<string>&v)
    {
        if(i==tiles.size())
        {
            if(mp[tiles]==false)
            {
                v.push_back(tiles);
                mp[tiles]=true;
            }
        }
        for(int j=i; j<tiles.size(); j++)
        {
            swap(tiles[i],tiles[j]);
            permute(tiles,i+1,v);
            swap(tiles[i],tiles[j]);
        }
    }
    int numTilePossibilities(string tiles) {
        vector<string> v;
        permute(tiles,0,v);
        vector<string> ans;
        int count=0;
        for(int i=0; i<v.size(); i++)
            subsets("",v[i],count);
        return count-1;
    }
};
