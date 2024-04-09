class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int res = 0, val = tickets[k]-1;
        for(int i=0;i<tickets.size();i++){
            if(tickets[i]<=val){
                res+=tickets[i];
                tickets[i]-=tickets[i];
            }
            else{
                res+=val;
                tickets[i]-=val;
            }

        }
        
        for(int i=0;i<=k;i++){
            if(tickets[i]>0){
                res++;
            }
        }
        return res;
    }
};
