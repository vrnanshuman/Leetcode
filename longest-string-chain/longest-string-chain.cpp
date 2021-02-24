class Solution {
public:
    
    bool validate(string &curr_word, string &word) {
        int small_len = word.length();
        int i=0;
        while(i<small_len && curr_word[i] == word[i])
            i++;
        while(i<small_len && curr_word[i+1] == word[i])
            i++;
        return i==small_len ;       
    }
    
    int longestStrChain(vector<string>& words) {
        int len = words.size();
        if(len == 1)
            return 1;
        sort(words.begin(), words.end(), [] (const string &a, const string &b)->bool {
            return a.length()<b.length();
        });
        vector<int> lis(len, 1);
        for(int i=1;i<len;i++) {
            int curr_word_len = words[i].length();
    
            for(int j=0;j<i;j++) {
                int word_len = words[j].length();
                if((word_len + 1 == curr_word_len) && validate(words[i], words[j])) { 
                    lis[i] = max(1+lis[j], lis[i]);
                }
            }
            
        }
        return *max_element(lis.begin(), lis.end());
    }
};