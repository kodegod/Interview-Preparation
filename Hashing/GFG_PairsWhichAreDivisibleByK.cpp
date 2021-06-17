//https://practice.geeksforgeeks.org/problems/pairs-which-are-divisible-by-41920/1

class Solution{
    public:
    int count4Divisibiles(int v[], int n)
    {
        // Complete the function
        map<int,int> mp;
        int k=4;
        for(int i=0; i<n; i++)
		    mp[v[i] % k]++;
    	int curr = 0;
    	for (int i = 0; i < (k / 2) + 1; i++)
    	{
    		int a = i;
    		int b = (k - i) % k;
    		int x = mp[a];
    		int y = mp[b];
    		if (a == b)
    			curr += ((x) * (x - 1)) / 2;
    		else
    			curr += x * y;
    	}
    	return curr;
    }
};
