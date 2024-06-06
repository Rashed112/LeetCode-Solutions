class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize !=0){
            return false;
        }
        map<int,int>m;
        for(auto x : hand){
            m[x]++;
        }
        while(!m.empty()){
            int currentCard = m.begin()->first;
            for(int i=0;i<groupSize;i++){
                if(m[currentCard+i] == 0){
                    return false;
                }
                m[currentCard + i]--;
                if(m[currentCard + i] < 1){
                    m.erase(currentCard+i);
                }
            }
        }
        return true;
    }
};

// Time: O(n*logn)
// Space: O(n)
