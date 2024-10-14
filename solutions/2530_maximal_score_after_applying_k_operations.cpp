class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;
        long long res = 0;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        while(k--){
            int temp = pq.top();
            pq.pop();
            res+=temp;
            temp = ceil(temp*1.0/3);
            pq.push(temp);
            
        }
        return res;
    }
};

// Time: O(nlogn)
// Space: O(n)
