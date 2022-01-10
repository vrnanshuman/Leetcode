class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> Stack;
        unordered_map<int, int> Map;
        int len2 = nums2.size();
        
        Stack.push(nums2[len2-1]);
        Map.insert({nums2[len2-1], -1});
        
        for(int i=len2-2;i>=0;i--) {
            while(!Stack.empty() && nums2[i] > Stack.top()) {
                Stack.pop();
            }
            if(Stack.empty())
                Map.insert({nums2[i], -1});
            else
                Map.insert({nums2[i], Stack.top()});
            Stack.push(nums2[i]);
        }
        
        vector<int> result(nums1.size(), 0);
        unordered_map<int, int>::iterator itr;
        
        for(int i=0;i<nums1.size();i++) {
            itr = Map.find(nums1[i]);
            result[i] = itr->second;
        }
        return result;
    }
};