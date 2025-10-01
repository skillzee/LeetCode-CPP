class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res=0;
        int filledBottles = numBottles;
        int emptyBottles = 0;
        while(filledBottles>0){
            res+=filledBottles;
            filledBottles = emptyBottles+filledBottles;
            emptyBottles = filledBottles%numExchange;
            filledBottles = filledBottles/numExchange;
        }
        return res;
    }
};