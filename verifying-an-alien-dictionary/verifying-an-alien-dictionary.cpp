class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> m;
        
        vector<int> wordMap(26,0);
        for(int i=0;i<order.length();i++) {
            wordMap[order[i]-'a'] = i;
        }
        
        string s1,s2;
        int l1, l2;
        
        for(int i=0;i<words.size()-1;i++) {
            s1 = words[i];
            s2 = words[i+1];
            
            l1 = l2 = 0;
            
            while(l1<s1.length() && l2<s2.length()) {
                if(s1[l1] == s2[l2]) {
                    l1++;l2++;
                } else {
                    if(wordMap[s1[l1]-'a'] > wordMap[s2[l2] - 'a'])
                        return false;
                    else {
                        break;
                    }
                }
            }
            if(l1 != s1.length() && l2 == s2.length())
                return false;
        }
        return true;
    }
};