class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        // Ye similar hai partitions with given difference jo gfg pe kiya tha do subsets mein baat do aur unn dono ka minus krke difference target ke equal hona chahiye

        int s1 = (target+total)/2;
        if(total < target) return 0;
        if((total+target)<0 || ((total+target) % 2) != 0) return 0;
        
        int n = nums.size();

        vector<vector<int>> dp(n+1, vector<int>(s1+1));
        for(int i = 0; i<n+1; i++){
            for(int j = 0;j<s1+1; j++){
                if(j == 0) dp[i][j] = 1;

                if(i == 0 and j !=0 ) dp[i][j] = 0;
            }
        }


        for(int i = 1; i<n+1; i++){
            for(int j = 0; j<s1+1; j++){
                if(nums[i-1]<=j){
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][s1];



    }
};