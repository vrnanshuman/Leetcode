class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l, r, mid, prev, next;
        l=0, r=arr.size()-1;
        
        while(l<=r) {
            mid = l + (r-l)/2;
            prev = mid-1< 0 ? -1: arr[mid-1];
            next = mid+1> arr.size()-1 ? -1: arr[mid+1];
            if(arr[mid] > prev && arr[mid] > next)
                return mid;
            else if(arr[mid] < next)
                l=mid+1;
            else
                r=mid-1;
        }
        return -1;
    }
};