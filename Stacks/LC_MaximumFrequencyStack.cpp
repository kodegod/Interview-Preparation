//https://leetcode.com/problems/maximum-frequency-stack/

class FreqStack {
public:
    int max_freq = 0;
    map<int,int> freq;
    map<int,stack<int>> mp;
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        mp[freq[val]].push(val);
        if(freq[val] >= max_freq)
            max_freq = freq[val];
    }
    
    int pop() {
        int ans = mp[max_freq].top();
        mp[max_freq].pop();
        if(mp[max_freq].empty())
            max_freq--;
        freq[ans]--;
        return ans;
    }
};
