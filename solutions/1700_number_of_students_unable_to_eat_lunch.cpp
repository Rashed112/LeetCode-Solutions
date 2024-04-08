class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int ones = 0, zeroes=0;
        for(auto x : students){
            if(x){
                ones++;
            }
            else{
                zeroes++;
            }
        }
        for(int i=0;i<sandwiches.size();i++){
            if(sandwiches[i]==0 && zeroes){
                zeroes--;
            }
            else if(sandwiches[i]==1 && ones){
                ones--;
            }
            else{
                return sandwiches.size()-i;
            }
        }
        return 0;
    }
};
