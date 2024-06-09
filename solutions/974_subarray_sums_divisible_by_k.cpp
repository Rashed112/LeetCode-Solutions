class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int count = 0, prefix = 0;
        m[0] = 1;

        for(int i=0;i<nums.size();i++){
            prefix+=nums[i];
            // here we're adding k to find remainder, so that
            // we can make negative remainder to equivalent positive one
            // which can't be just done with abs()
            int remainder = (prefix % k + k) % k;
            cout<<remainder<<endl;
            if(m.find(remainder) != m.end()){
                count+=m[remainder];
            }
            m[remainder]++;
        }
        
        return count;
    }
};
