class Solution {
public:
    int maxArea(vector<int>& height) {
        int l,r, maxWater = 0;
        l=0,r=height.size()-1;
        
        while(l<r) {
            maxWater = max(maxWater, (r-l)*min(height[l], height[r]));
            if(height[l] == height[r]) {
                l++;
                r--;
            } else if(height[l] < height[r])
                l++;
            else
                r--;     
        }
        return maxWater;
    }
};