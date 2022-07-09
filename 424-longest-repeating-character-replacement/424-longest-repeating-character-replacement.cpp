class Solution {
public:
    
    int characterReplacement(string s, int k) {
        int i,j, maxSize, maxFreq;
        vector<int> charFreq(26,0);
        maxSize = maxFreq = 0;
        i=j=0;
        
        while(j<s.length()) {
            
            charFreq[s[j] - 'A'] +=1;
            maxFreq = *max_element(charFreq.begin(), charFreq.end());
            
            if(j-i+1 - maxFreq <= k){
                maxSize = max(maxSize, j-i+1);
            }
            
            while(j-i+1 - maxFreq > k) {
                charFreq[s[i] - 'A'] -= 1;
                maxFreq = *max_element(charFreq.begin(), charFreq.end());
                i++;
            }
            j++;
        }
        return maxSize;
    }
};