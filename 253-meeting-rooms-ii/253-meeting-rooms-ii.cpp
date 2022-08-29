class Solution {
    struct Timestamp {
        int t;
        bool isStart;
        
        bool operator < (const Timestamp& that) const {
            if(t < that.t)
                return true;
            if(t == that.t && !isStart && that.isStart)
                return true;
            return false;
        }
    };
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int minRooms = 0;
        int current = 0;
        vector<Timestamp> t;
        
        for(vector<int> interval: intervals) {
            t.push_back(Timestamp{interval[0], true});
            t.push_back(Timestamp{interval[1], false});
        }
        sort(t.begin(), t.end());
        
        for(Timestamp x:t) {
            if(x.isStart) {
                current+=1;
                minRooms = max(minRooms, current);
            } else {
                current--;
            }
        }
        return minRooms;
    }
};