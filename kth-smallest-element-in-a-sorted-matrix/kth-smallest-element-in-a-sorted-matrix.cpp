class Solution {
public:
    struct element {
        bool operator<(const element& that) const{
            return val > that.val;
        }
        
        int val, row, col;
    };
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<element, vector<element>> min_heap;
        int n = matrix.size();
        int rows = min(n, k);
        
        for(int i=0;i<rows;i++) {
            min_heap.emplace(element{matrix[i][0], i, 0});
        }
        int top;
        while(k!=0) {
            auto popped = min_heap.top();
            min_heap.pop();
            top = popped.val;
            k--;
            if(popped.col != n-1){
                min_heap.emplace(element{matrix[popped.row][popped.col + 1], popped.row, popped.col+1});
            }
                
        }
        return top;
        
    }
};