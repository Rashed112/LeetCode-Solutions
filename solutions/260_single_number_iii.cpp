class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_sum = 0;
        for(int i=0;i<nums.size();i++){
            xor_sum ^= nums[i];
        }
        int diff_bit = 1;
        // finding the position of different bit to separate both numbers
        while(! (diff_bit & xor_sum)){
            diff_bit = diff_bit<<1;
        }
        vector<int>res(2,0);
        for(int i=0;i<nums.size();i++){
            if(diff_bit & nums[i]){
                res[0] ^= nums[i];
            }
            else{
                res[1] ^= nums[i];
            }
        }
        return res;
    }
};
