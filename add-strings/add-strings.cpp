class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string s = "";
        
        int sum, carry;
        carry = 0;
        int l1, l2;
        l1 = l2 = 0;
        while(l1 < num1.length() && l2 < num2.length()) {
            sum = (num1[l1]-'0') + (num2[l1]-'0') + carry;
            s += to_string(sum%10);
            carry = sum/10;
            l1++; l2++;
        }
        
        while(l1 < num1.length()) {
            sum = (num1[l1]-'0') + carry;
            s += to_string(sum%10);
            carry = sum/10;
            l1++;
        }
        
        while(l2 < num2.length()) {
            sum = (num2[l2]-'0') + carry;
            s += to_string(sum%10);
            carry = sum/10;
            l2++;
        }
        if(carry)
            s += to_string(carry);
        reverse(s.begin(), s.end());
        return s;
        
    }
};