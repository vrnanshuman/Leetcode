class Solution {
public:
    int trap(vector<int>& height) {
        int l,r,lmax,rmax, water = 0;
        l=0;r=height.size()-1;
        lmax = rmax = 0;
        
        while(l<r) {
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);
            
            if(lmax < rmax) {
                water += lmax - height[l];
                l++;
            } else {
                water += rmax - height[r];
                r--;
            }
        }
        return water;
    }
};