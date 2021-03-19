void moveNeg(vector<int>& v) {
        int n=v.size();
        int i=0;
        int j=n-1;
        while(i<=j)
        {
            if(v[i]<0&&v[j]<0)
                i++;
            else if(v[i]==0)
                swap(v[i++],v[j--]);
            else
                j--;
        }
    }
