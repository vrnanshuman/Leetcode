class SparseVector {
public:
    unordered_map<int, int> vMap;
    SparseVector(vector<int> &nums) {
        for(int i=0;i<nums.size();i++) {
            if(nums[i]!=0)
                vMap.insert({i,nums[i]});
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        unordered_map<int, int>::iterator itrVec;
        int dot = 0;
        for(auto itr=vMap.begin();itr!=vMap.end();itr++) {
            itrVec = vec.vMap.find(itr->first);
            if(itrVec != vec.vMap.end()) {
                dot += itrVec->second * itr->second;
            }
        }
        return dot;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);