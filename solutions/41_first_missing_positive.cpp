// Approach-1: Using Sorting
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){

                if(nums[i] == res){
                    res++;
                }
                else if(nums[i]<res){
                    continue;
                }
                else{
                    break;
                }
            }
        }
        return res;
    }
};
// Time: O(nlogn)
// Space: O(n)


// Approach-2: Using Hashmap
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>m;
        for(auto i : nums){
            m[i]++;
        }
        for(int i=1;i<=n;i++){
            if(!m[i]){
                return i;
            }
        }
        return n+1;
    }
};
// Time: O(n)
// Space: O(n)


// Approach-3: Using given input array as our extra hashmap memory
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // inserting a dummy value in front to align our possible result value and
        // index same and later store all useless value here
        nums.insert(nums.begin(), 0);
        int n = nums.size();

        // observation: possible ans range is [1, n+1]

        // delete useless elements
        for(auto &x : nums){
            if(x<0 || x>=n){
                x = 0;
            }
        }

        // use the index as the hash to record the frequency of each number
        // and here all useless elements which is turned to 0, those numbers
        // frequency will be stored in 0th index, so can check from next idx later
        for(int i=0;i<n;i++){
            nums[nums[i]%n] += n;
        }

        for(int i=1;i<n;i++){
            if(nums[i]/n==0){
                return i;
            }
        }
        return n;
        
    }
};
// Time: O(n)
// Space: O(1)
