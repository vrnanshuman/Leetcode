class Solution {
    bool comp(vector<int> &a, vector<int> &b){
        return a[0]==b[0] && a[1]==b[1] && a[2]==b[2] ? true: false;
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        if(len<3)
            return {};
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int l,r,sum;
        for(int i=0;i<len;i++){
            if(i!=0 && nums[i] == nums[i-1])
                continue;
            l=i+1, r=len-1;
            while(l<r){
                sum = nums[i] + nums[l] + nums[r];
                if(sum == 0){
                    result.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while(l<r && nums[l] == nums[l-1])
                        l++;
                } else if(sum<0){
                    l++;
                } else
                    r--;
            }
        }
        return result;
    }
};