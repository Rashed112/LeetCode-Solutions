class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0, r=n-1, ans=0;
        while(l<r){
            ans = max(ans, (r-l)*min(height[l], height[r]));
            if(height[l]<height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return ans;
    }
};
