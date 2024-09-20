class Solution {
public:
    bool isHappy(int N) {

        if(N==7){
            return true;
        }
        
        if(N/10 == 0){
            if(N == 1){
                return true;
            }else{
                return false;
            }
            
        }
        
        int sum = 0;
        while(N){
            int rem = N%10;
            rem = rem*rem;
            sum+=rem;
            N=N/10;
        }
        return isHappy(sum);
    }
};