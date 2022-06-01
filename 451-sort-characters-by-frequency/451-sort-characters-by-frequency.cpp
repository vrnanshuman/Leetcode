class Solution {
public:
    string frequencySort(string s) {
        if(s.length() <= 2)
            return s;
        
        unordered_map<char, int> m;
        
        for(int i=0;i<s.length();i++) {
            if(m.find(s[i]) != m.end()) {
                m[s[i]] += 1;
            } else {
                m.insert({s[i],1});
            }
        }
        
        vector<pair<char,int>> v;
        for(auto itr : m) {
            v.push_back({itr.first, itr.second});
        }
        
        sort(v.begin(), v.end(), [](const pair<char,int> &a, const pair<char,int>&b) {
            return a.second > b.second;
        });
        
        string sorted = "";
        for(auto p : v) {
            for(int j=0;j<p.second;j++)
                sorted += p.first;
        }
        return sorted;
    }
};