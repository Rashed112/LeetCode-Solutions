// Approach-1:
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int>m;
        int x = nums.size()/3;
        for(auto n : nums){
            m[n]++;
        }
        vector<int>res;
        for(auto n : m){
            if(n.second>x){
                res.push_back(n.first);
            }
        }
        return res;
    }
};

// Approach-2:
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = 0, candidate2 = 0;
        int cnt1 = 0, cnt2 = 0;
        for(int i = 0; i<nums.size(); i++){ 
             if(cnt1 == 0 && nums[i] != candidate2){
                cnt1 = 1; 
                candidate1 = nums[i];
             }
             else if(cnt2 == 0 && nums[i] != candidate1){
                cnt2 = 1;
                candidate2 = nums[i];
             }
             else if(candidate1 == nums[i]){
                cnt1++;
             }
             else if(candidate2 == nums[i]){
                cnt2++;
             }
             else{
                cnt1--;
                cnt2--;
             }
        }
        vector<int>res;
        int x = nums.size()/3;
        cnt1 = 0; 
        cnt2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]==candidate1){
                cnt1++;
            }
            else if(nums[i]== candidate2){
                cnt2++;
            }
        }
        if(cnt1>x){
            res.push_back(candidate1);
        }
        if(cnt2>x){
            res.push_back(candidate2);
        }
        return res;
    }
};
