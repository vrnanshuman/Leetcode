class Solution {
public:
    int findTheWinner(int n, int k) {
        list<int> friends;
        
        for(int i=1;i<=n;i++)
            friends.push_back(i);
        
        int cursorPos = 0;
        while(friends.size()>1) {
            cursorPos = (cursorPos+k-1) % friends.size();
            auto cursorItr = next(friends.begin(),cursorPos);
            // cout<<"Del "<<*cursorItr<<endl;
            friends.erase(cursorItr);
            // cursorPos = (cursorPos+1)%friends.size();
        }
        return *friends.begin();
    }
};