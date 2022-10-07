/*
* it's a problem where if we use hashmap (which store val:ind) it's complexity would reduce
* plus in this case, we have to use a clever trick of assuming the hashmap null at first and update it later step by step..in this case, 
if target = 4 and first we find 3 and it's index and diff is (4-3)=1 and we'll check if the diff is in the hashmap, if it's in, then it would be the ans, 
otherwise we update the hashmap

*The basic idea is to maintain a hash table for each element num in nums, using num as key and its index (0-based) as value. For each num, search for (target - num)
in the hash table. If it is found and is not the same element as num, then we are done.
The code is as follows. Note that each time before we add num to mp, we search for target - num first and so we will not hit the same element.
*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int> hashMap;
        
        
        for(int i=0;i<nums.size();i++){
            int diff = target - nums[i];
            if(hashMap.find(diff) != hashMap.end()){
                return {hashMap[diff], i};
            }
            hashMap[nums[i]] = i; 
        }
        return {}; /*as there is guranteed ans, so prevous return will return the ans, this return won't be used*/
    }
};
