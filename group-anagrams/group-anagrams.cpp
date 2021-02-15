class Solution {
public: 
    void getSorted(string &a, string &b) {
        vector<int> m(26,0);
        for(int i=0;i<a.size();i++)
            m[a[i]-'a']++;
        for(int i=0;i<m.size();i++) {
            while(m[i]!=0) {
                char c = 97+i;
                b += c;
                m[i]--;
            }
        }
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groups;
        unordered_map<string, vector<string>> m;
        int len = strs.size();
        if(len == 1)
            return {{strs[0]}};
        int i,j, flag;
        for(i=0;i<len;i++) {
            string b = "";
            getSorted(strs[i], b);
            auto itr = m.find(b);
            if(itr!=m.end())
                itr->second.push_back(strs[i]);
            else
                m.insert({b,{strs[i]}});
        }
        
        for(auto itr = m.begin();itr!=m.end();itr++)
            groups.emplace_back(itr->second);
        
        return groups;
    }
};