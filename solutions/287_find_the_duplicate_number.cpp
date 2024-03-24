// Approach -1:
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
    
        for(auto x: nums){
            int temp = abs(x);
            if(nums[temp]<0){
                return temp;
            }
            nums[temp]=-nums[temp];
        }
        return -1;
    }
};

// Approach-2: 
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[nums[0]];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        slow = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
            cout<<slow<<" "<<fast<<endl;
        }
        return slow;
        
    }
};
