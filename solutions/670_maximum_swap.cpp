class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int  max_i= -1, swap_i=-1, swap_j=-1;
        for(int i=s.size()-1;i>=0;i--){
            if(max_i == -1 || s[i]>s[max_i]){
                
                max_i = i;
                
            }
            if(s[i] < s[max_i]){
                swap_j = max_i;
                swap_i = i;
            }
        }
        if(swap_i != -1 && swap_j != -1){

            swap(s[swap_i], s[swap_j]);
        }

        return stoi(s);
    }
};
