class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> m;
        int l = 0, r = 0, res = 0;
        while(r<fruits.size()){
            m[fruits[r]]++;
            
            if(m.size()<= 2){
                res = max(res, r-l+1);
                r++;
            }
            else if(m.size()> 2){
                while(m.size()>2){
                    m[fruits[l]]--;
                    if(m[fruits[l]]==0){
                        m.erase(fruits[l]);
                    }
                    l++;
                }
                r++;
            }
        }
        return res;
    }
};

// Time: O(n)
// Space: O(1), as only two key will be stored
