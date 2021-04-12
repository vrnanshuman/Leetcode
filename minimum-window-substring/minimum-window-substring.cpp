class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        
        for(char c : t) {
            auto itr = m.find(c);
            if(itr!=m.end())
                itr->second++;
            else
                m.insert({c, 1});
        }
        
        int i,j, start, end, min_size, map_count;
        min_size = INT_MAX;
        i = j = 0;
        start = end = -1;
        map_count = m.size();
        while(j<s.length()) {
            
            if(map_count > 0) {
                auto itr = m.find(s[j]);
                
                if(itr!=m.end()) {
                    if(itr->second == 1){
                        map_count--;
                    }
                    itr->second--;
                }
                j++;
            } else {
                while(map_count == 0) {
                    if(j-i < min_size) {
                        start = i;
                        end = j;
                        min_size = j-i;
                    }
                    auto itri = m.find(s[i]);
                    if(itri != m.end()) {
                        itri->second++;
                        if(itri->second == 1)
                            map_count++; 
                    }
                    i++;
                }
            }
        }
        while(i<s.length() && map_count == 0) {
            if(j-i < min_size) {
                start = i;
                end = j;
                min_size = j-i;
            }
            auto itri = m.find(s[i]);
            if(itri != m.end()) {
                itri->second++;
                if(itri->second == 1)
                    map_count++;
            }
            i++;
        }
        if(start == -1)
            return "";
        return s.substr(start, end-start);
        
    }
};