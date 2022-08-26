class Solution {
public:
    string expand(int k, string s) {
        string tmp = "";
        for(int i=1;i<=k;i++){
            tmp+=s;
        }
        return tmp;
    }
    
    string getString(string s, int& idx) {
        if(idx == s.length())
            return "";
        string encoded = "";
        while(idx<s.length()) {
            if(s[idx] == ']'){
                idx++;
                return encoded;
            }
            string k = "";
            while(isdigit(s[idx]) && idx<s.length()) {
                k+=s[idx++];
            }
            if(k.compare("") != 0){
                idx++;
                encoded += expand(stoi(k), getString(s, idx));
            }
            else
                encoded += s[idx++];
        }
        return encoded;
    }
    
    string decodeString(string s) {
        int idx = 0;
        return getString(s,idx);
    }
};