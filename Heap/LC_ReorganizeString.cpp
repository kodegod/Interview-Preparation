//https://leetcode.com/problems/reorganize-string/

// Good Q

class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        priority_queue<pair<int, char>> pq;
		map<char, int> mp;
		for (int i = 0; i < n; i++)
			mp[s[i]]++;
		for (auto it : mp)
			pq.push({it.second, it.first});
		char prev = 'A';
		string ans = "";
		while (!pq.empty())
		{
			char ch = pq.top().second;
			int freq = pq.top().first;
			pq.pop();
			pair<int, char> temp = {freq, ch};
			if (ch == prev)
			{
				if (pq.empty())
					break;
				ch = pq.top().second;
				freq = pq.top().first;
				pq.pop();
				pq.push(temp);
			}
			ans.push_back(ch);
			if (freq > 1)
				pq.push({freq - 1, ch});
			prev = ch;
		}
		if (ans.size() != n)
			return "";
		else
			return ans;
    }
};
