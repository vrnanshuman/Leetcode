class Solution {
public:
    unordered_map<char, int> orderMap;
    
    string customSortString(string order, string s) {
        
        for(int i=0;i<order.length();i++) {
            orderMap.insert({order[i], i});
        }
        sort(s.begin(), s.end(), [&, this] (const char &a, const char &b) {
            int idxa, idxb;
            idxa = idxb = -1;
            auto itra = this->orderMap.find(a);
            auto itrb = this->orderMap.find(b);
            if(itra != this->orderMap.end())
                idxa = itra->second;
            if(itrb != this->orderMap.end())
                idxb = itrb->second;
            return idxa<idxb;
                
        });
        return s;
    }
};