class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        stack<int> idxStack;
        unordered_set<int> idxSet;
        
        for(int i=0;i<s.length();i++) {
            if(isalpha(s[i]))
                continue;
            if(s[i] == '(')
                idxStack.push(i);
            else {
                if(idxStack.empty())
                    idxSet.insert(i);
                else
                    idxStack.pop();
            }
        }
        
        while(!idxStack.empty()) {
            idxSet.insert(idxStack.top());
            idxStack.pop();
        }
        string result = "";
        for(int i=0;i<s.length();i++) {
            auto itr = idxSet.find(i);
            if(itr == idxSet.end()) {
                result += s[i];
            }
        }
        return result;
        
        
    }
};