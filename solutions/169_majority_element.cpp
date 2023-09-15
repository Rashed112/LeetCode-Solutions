class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Boyer Moore Algo
        int majority = nums[0], cnt = 1;
        for(int i=1;i<nums.size();i++){
            if(cnt==0){
                cnt++;
                majority = nums[i];
            }
            else if(majority == nums[i]){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return majority;
    }
};
