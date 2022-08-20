class Solution {
    struct Word{
        string w;
        int freq;
        
        bool operator < (const Word &that) const {
            if(freq == that.freq)
                return w < that.w;
            return freq > that.freq;
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string,Word> m;
        
        for(string word:words) {
            auto itr = m.find(word);
            if(itr!=m.end())
                itr->second.freq++;
            else
                m.insert({word,Word{word,1}});
        }
        
        priority_queue<Word, vector<Word>> min_heap;
        
        for(auto p : m) {
            min_heap.push(p.second);
            if(min_heap.size() > k)
                min_heap.pop();
        }
        
        vector<string> result;
        
        while(!min_heap.empty()) {
            result.push_back(min_heap.top().w);
            min_heap.pop();
        }
        reverse(result.begin(), result.end());
        return result;
        
    }
};