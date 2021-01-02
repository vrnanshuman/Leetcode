class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if(len == 1)
            return s;
        vector<vector<int>> matrix(len, vector<int>(len, 0));
        int max_len = 1;
        string lps = s.substr(0,1);
        int start;
        
        for(int i=0;i<len;i++) {
            matrix[i][i] = 1;
            if(s[i] == s[i+1]){
                matrix[i][i+1] = 1;
                max_len = 2;
                lps = s.substr(i, 2);
            }
        }
        
        int left, right;
        int left_index, right_index;
        left_index  = right_index = -1;
        start = 0;
        for(int x = 2; x < len; x++) {
            left = start, right = x;
            while(right < len) {
                int curr_len = right - left + 1;
                if(s[left] == s[right] && matrix[left+1][right-1]==1) {
                    matrix[left][right] = 1;
                    if(curr_len > max_len) {
                        max_len = curr_len;
                        left_index = left;
                        right_index = right;
                    }
                }
                left++;
                right++;
            }
        }
        if(left_index!=-1)
            lps = s.substr(left_index, right_index-left_index+1);
        return lps;
    }
};
