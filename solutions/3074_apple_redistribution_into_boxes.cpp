class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(), capacity.rend());
        int cnt = 0, target =0;
        for(int i=0;i<apple.size();i++){
            target+=apple[i];
        }
        int res = 0, sum =0;;
        for(int j=0;j<capacity.size();j++){
            sum+=capacity[j];
            
            if(sum<target){
                res++;
            }
            else{
                res++;
                break;
            }
        }
        return res;
    }
};
