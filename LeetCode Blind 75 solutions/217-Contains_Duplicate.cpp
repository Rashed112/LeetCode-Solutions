class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                return true;
            }
        }
        return false;
    }
};
//TC: O(nlogn) //because of sorting
//SC: O(1)

/*but sacrificing the spcae complexity , we can improve time complexity..
for this, we've to use an empty unordered_hashmap  and we'll check if a value is in the hashmap and if not then put it in the hashmap.
*/
