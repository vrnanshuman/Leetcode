class Leaderboard {
    unordered_map<int,int> scores;
    map<int, int> bst;
public:
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        int oldScore;
        int newScore;
        if(scores.find(playerId)!=scores.end()) {
            oldScore = scores[playerId];
            auto itr = bst.find(oldScore);
            if(itr->second == 1) {
                bst.erase(itr);
            } else {
                itr->second--;
            }
            newScore = oldScore + score;
            itr = bst.find(newScore);
            if(itr!=bst.end()) {
                itr->second++;
            } else {
                bst.insert({newScore, 1});
            }
            scores[playerId] = newScore;
        } else {  
            auto itr = bst.find(score);
            if(itr!=bst.end()) {
                itr->second++;
            } else {
                bst.insert({score, 1});
            }
            scores[playerId] = score;
        }
    }
    
    int top(int K) {
        int sum = 0;
        int count = 0;
        for(auto itr=bst.rbegin();itr!=bst.rend();itr++) {
            int times = itr->second;
            int value = itr->first;
            
            for(int i=0;i<times;i++) {
                if(count == K)
                    break;
                sum+=value;
                count++;
            }
            if(count==K)
                break;
        }
        return sum;
    }
    
    void reset(int playerId) {
        auto itr = bst.find(scores[playerId]);
        if(itr!=bst.end()) {
            if(itr->second == 1)
                bst.erase(itr);
            else
                itr->second--;
        }
        scores.erase(playerId);
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */