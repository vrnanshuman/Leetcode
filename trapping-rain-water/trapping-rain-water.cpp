class Solution {
public:
    
    void computeMaxLeft(vector<int> &height, vector<int> &maxLeft) {
        
        maxLeft[0] = height[0];
        for(int i=1;i<height.size();i++) {
            maxLeft[i] = max(maxLeft[i-1], height[i]);
        }
    }
    
    void computeMaxRight(vector<int> &height, vector<int> &maxRight) {
        
        int n = height.size();
        maxRight[n-1] = height[n-1];
        
        for(int i=n-2;i>=0;i--) {
            maxRight[i] = max(maxRight[i+1], height[i]);
        }
    }    
    
    int trap(vector<int>& height) {
        if(height.size() <= 2)
            return 0;
        
        vector<int> maxLeft(height.size(), 0);
        vector<int> maxRight(height.size(), 0);
        computeMaxLeft(height, maxLeft);
        computeMaxRight(height, maxRight);
        
        int water = 0;
        for(int i=0;i<height.size();i++) {
            water += min(maxLeft[i], maxRight[i]) - height[i];
        }
        
        return water;
    }
};