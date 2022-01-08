class Solution {
public:
    
    bool getMaxLength(vector<int>& ribbons, int mid, int k) {
        int count=0;
        // cout<<"mid "<<mid<<endl;
        for(int ribbon : ribbons) {
            count += ribbon/mid;
        }
        // cout<<"count "<<count<<endl;
        return count>=k;
    }
    
    int maxLength(vector<int>& ribbons, int k) {
        int l,r,mid, result=0;
        l=1;
        r=*max_element(ribbons.begin(), ribbons.end());
        
        while(l<=r) {
            mid = l+(r-l)/2;
            if(getMaxLength(ribbons, mid, k)){
                result = mid;
                l=mid+1;
            } else {
                r=mid-1;
            }
        }
        return result;
    }
};