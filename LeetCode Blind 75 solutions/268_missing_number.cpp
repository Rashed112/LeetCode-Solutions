//Solution-1: Math - TC O(n) | SC O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total = n*(n+1)/2, sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        return total-sum;
    }
};

//Solution-2: Unordered_map - TC O(n) | SC O(n)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>ump;
        for(int i=0;i<n;i++){
            ump[nums[i]]++;
        }
        for(int i=0;i<=n;i++){
            if(ump.find(i)==ump.end()){
                return i;
            }
        }
        return -1;
    }
};
