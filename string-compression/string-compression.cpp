class Solution {
public:
    int compress(vector<char>& chars) {
        int len = chars.size();
        if(len == 1)
            return 1;
        int count = 1;
        int i;
        vector<char> result;
        for(i=1;i<len;i++) {
            if(chars[i] != chars[i-1]) {
                result.emplace_back(chars[i-1]);
                if(count != 1){
                    string tmp = to_string(count);
                    for(char c:tmp)
                        result.emplace_back(c);
                }
                count = 1;
            } else {
                count++;
            }
        }
        result.emplace_back(chars[i-1]);
        if(count > 1){
            string tmp = to_string(count);
            for(char c:tmp)
                result.emplace_back(c);
        }
        chars.clear();
        chars = result;
        return chars.size();
    }
};