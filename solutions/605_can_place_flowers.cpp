class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        //inserting dummy 0 in the begining and ending of the vector
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        for(int i=1;i<flowerbed.size()-1;i++){
            if(flowerbed[i-1]+flowerbed[i]+flowerbed[i+1]==0){
                n--;
                i++;
            }
            if(n<0) return true;
        }
        return n<=0;
    }
};
