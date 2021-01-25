class Solution {
public:
    class point{
    public:
        int val;
        bool start;
        point(int val, bool start) {
            this->val = val;
            this->start = start;
        }
    };
    
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int len = intervals.size();
        if(len == 1)
            return 1;
        vector<point> points;
        for(int i=0;i<len;i++) {
            points.emplace_back(point(intervals[i][0], true));
            points.emplace_back(point(intervals[i][1], false));
        }
        sort(points.begin(), points.end(), [] (const point &a, const point &b) -> bool {
            if(a.val == b.val)
                return a.start ? false : true;
            return a.val < b.val;
        });
        int max_rooms = 1;
        int count = 1;
        for(int i=1;i<2*len;i++) {
            if(points[i].start)
                count++;
            else
                count--;
            max_rooms = max(max_rooms, count);
        }
        return max_rooms;
    }
};
