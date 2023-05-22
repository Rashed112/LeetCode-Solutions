class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        unordered_set<int> ump(nums1.begin(), nums1.end());
        for(int i=0;i<nums2.size();i++){
            if(ump.find(nums2[i])!=ump.end()){
                res.push_back(nums2[i]);
                ump.erase(nums2[i]);
            }
        }
        return res;
    }
};
