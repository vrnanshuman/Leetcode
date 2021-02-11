class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(int i=0;i<tasks.size();i++) {
            freq[tasks[i]-'A']++;
        }
        sort(freq.begin(), freq.end());
        int max_freq_freq = 1;
        for(int i=24;i>=0;i--){
            if(freq[i] == freq[i+1])
                max_freq_freq++;
            else
                break;
        }
        int min_cycles = (n+1) * (freq[25]-1) + max_freq_freq;
        return min_cycles > tasks.size() ? min_cycles : tasks.size();
        
    }
};