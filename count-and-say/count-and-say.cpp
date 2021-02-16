class Solution {
public:
    
    string translate(string &seq) {
        string new_seq = "";
        int count = 1;
        int i;
        for(i=1;i<seq.length();i++) {
            if(seq[i]!=seq[i-1]) {
                new_seq += to_string(count) + string(1,seq[i-1]);
                count = 1;
            } else {
                count++;
            }
        }
        new_seq += to_string(count) + string(1,seq[i-1]);
        return new_seq;
    }
    
    string countAndSay(int n) {
        if(n==1)
            return "1";
        string seq = "1";
        for(int i=2;i<=n;i++) {
            seq = translate(seq);
        }
        return seq;
    }
};