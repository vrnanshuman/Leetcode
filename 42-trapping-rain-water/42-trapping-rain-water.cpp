class Solution {
public:
    
    vector<int> findMaxLeft(vector<int>& height) {
        int maxLeft = INT_MIN;
        vector<int> left(height.size());
        for(int i=0;i<height.size();i++) {
            maxLeft = max(maxLeft, height[i]);
            left[i] = maxLeft;
        }
        return left;
    }
    
    void findMaxRight(vector<int>& height, vector<int> &right) {
        int maxRight = INT_MIN;
        for(int i=height.size()-1;i>=0;i--) {
            maxRight = max(maxRight, height[i]);
            right[i] = min(right[i], maxRight);
        }

    }
    
    int trap(vector<int>& height) {
        vector<int> minHeight = findMaxLeft(height);
        findMaxRight(height, minHeight);
        int water = 0;
        for(int i=0;i<height.size();i++) {
            water += minHeight[i] - height[i];
        }
        return water;
    }
};