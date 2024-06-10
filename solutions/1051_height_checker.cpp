// Approach - 1 : Using Built-in Sort
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>v(heights.begin(), heights.end());
        sort(v.begin(), v.end());
        int count = 0;
        for(int i=0;i<heights.size();i++){
            if(heights[i]!=v[i]){
                count++;
            }
        }
        return count;
    }
};

// Approach - 2 : Using Counting Sort
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>v(101, 0);
        for(auto x : heights){
            v[x]++;
        }
        vector<int>expected(heights.size(), 0);
        int j=0;
        for(int i=1;i<101;i++){
            while(v[i]){
                expected[j++]=i;
                v[i]--;
            }
        }
        int count = 0;
        for(int i=0;i<heights.size();i++){
            if(heights[i]!=expected[i]){
                count++;
            }
        }
        return count;
    }
};
