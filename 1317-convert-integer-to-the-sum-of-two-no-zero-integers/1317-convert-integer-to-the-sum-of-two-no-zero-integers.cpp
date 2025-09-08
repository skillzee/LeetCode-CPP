class Solution {
public:
    bool noZero(int n){
        while(n>0){
            int rem = n%10;
            if(rem == 0){
                return false;
            }

            n=n/10;
        }

        return true;
    }

    vector<int> getNoZeroIntegers(int n) {
        
        for(int i = 1; i<=n; i++){
            int ele1 = i;
            int ele2 = n-i;
            if(noZero(ele1) and noZero(ele2)){
                return {ele1, ele2};
            }
        }

        return {};
    }
};