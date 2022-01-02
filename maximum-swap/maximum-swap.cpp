class Solution {
public:
    
    vector<int> toVector(int num) {
        vector<int> v;
        while(num) {
            v.emplace_back(num%10);
            num /= 10;
        }
        reverse(v.begin(), v.end());
        return v;
    }
    
    int toNum(vector<int> v) {
        int num = 0;
        for(int val : v) {
            num = num*10 + val;
        }
        return num;
    }
    
    int maximumSwap(int num) {
        vector<int> digits = toVector(num);
        vector<int> numMap(10, -1);
        
        for(int i=0;i<digits.size();i++) {
            numMap[digits[i]] = i;
        }
        
        for(int i=0;i<digits.size();i++) {
            for(int j=9;j>=0;j--) {
                if(j>digits[i]) {
                    if(numMap[j]!=-1 && i<numMap[j]) {
                        int tmp = digits[i];
                        digits[i] = j;
                        digits[numMap[j]] = tmp;
                        return toNum(digits);
                    }
                }
            }
        }
        return num;
    }
};