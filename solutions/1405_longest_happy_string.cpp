class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>>pq;
        if(a){
            pq.push({a, 'a'});
        }
        if(b){
            pq.push({b, 'b'});
        }
        if(c){
            pq.push({c, 'c'});
        }

        string ans = "";
        while(!pq.empty()){
            pair<int, char>one = pq.top();
            pq.pop();
            if(ans.size()>1 && ans[ans.size()-1]==one.second && ans[ans.size()-2]==one.second){
                if(pq.empty()){
                    break;
                }
                pair<int, char>two = pq.top();
                pq.pop();
                ans+=two.second;
                if(--two.first>0){
                    pq.push(two);
                }
                pq.push(one);
            }
            else{
                ans+=one.second;
                if(--one.first>0){
                    pq.push(one);
                }
            }
            
        }
        return ans;
    }
};
