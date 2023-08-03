//Solution-1
//Time: O(n), Space: O(n)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int, int>ump;
        vector<int>res;
        for(int i=0;i<nums.size();i++){
            ump[nums[i]]++;
        }
        for(int i=1;i<=nums.size();i++){
            if(ump.find(i) == ump.end()){
                res.push_back(i);
            }
        }
        return res;
    }
};
//Solution-2
//Time: O(n), Space: O(1)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>res;
        for(int i=0;i<nums.size();i++){
            nums[abs(nums[i])-1] = - abs(nums[abs(nums[i])-1]);
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                res.push_back(i+1);
            }
        }
        return res;
    }
};
