class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        int poss = 0;

        for(int i = 0; i<size; i++){
            int curr = flowerbed[i];

            int left = (i>0)?flowerbed[i-1]:0;
            int right = (i<size-1)? flowerbed[i+1]:0;

            if(left == 0 and right == 0){
                if(curr == 0){
                    poss++;
                    flowerbed[i] = 1;
                }
            }
        }

        return poss>=n;
    }
};