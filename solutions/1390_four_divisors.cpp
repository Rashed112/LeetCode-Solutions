class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, d=0;
        for(auto x: nums){
            int currS=0, cnt=0;
            for(int i=2;i*i<=x;i++){
                if(x%i==0){
                    d=i;
                    cnt++;
                    currS+=i;
                }
            }
            if(cnt==1 && d!=x/d){
                sum+=1+x+x/d+currS;
            }
        }
        return sum;
    }
};
