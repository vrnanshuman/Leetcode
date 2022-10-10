class Solution {
    struct Element {
        char ch;
        int count;
    };
public:
    
    string expand(Element &e) {
        string result = "";
        while(e.count>0) {
            result +=e.ch;
            e.count--;
        }
        return result;
    }
    
    string removeDuplicates(string s, int k) {
        stack<Element> st;
        string result="";
        
        for(int i=0;i<s.length();i++) {
            if(st.empty())
                st.push(Element{s[i],1});
            else {
                auto top = st.top();
                if(s[i] == top.ch) {
                    if(top.count == k-1)
                        st.pop();
                    else {
                        st.pop();
                        st.push(Element{top.ch, top.count+1});
                    }
                } else {
                    st.push(Element{s[i],1});
                }
            }
        }
        while(!st.empty()) {
            result = expand(st.top()) + result;
            st.pop();
        }
        return result;
        
    }
};