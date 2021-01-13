class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int l,r;
        int max_area = INT_MIN;
        l=0;
        r=len-1;
        while(l<r) {
            max_area = max(max_area, (r-l)*min(height[l], height[r]));
            if(height[l]<height[r])
                l++;
            else
                r--;
        }
        return max_area;
    }
};
