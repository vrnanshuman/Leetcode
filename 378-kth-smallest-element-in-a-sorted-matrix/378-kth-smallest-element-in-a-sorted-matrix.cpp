class Solution {
    struct Num {
        int row;
        int col;
        int len;
        int value;
        
        bool operator < (const Num &a) const {
            return value > a.value;
        }
    };
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<Num, vector<Num>> min_heap;
        
        int rows,cols;
        rows = matrix.size();
        cols = matrix[0].size();
        
        for(int i=0;i<rows;i++) {
            min_heap.push(Num{i,0,cols,matrix[i][0]});
        }
        Num top;
        
        while(!min_heap.empty()) {
            top = min_heap.top();
            min_heap.pop();
            k--;
            if(k==0)
                return top.value;
            
            if(top.col+1 < top.len)
                min_heap.push(Num{top.row,top.col+1,cols,matrix[top.row][top.col+1]});
            
        }
        return 0;
        
    }
};