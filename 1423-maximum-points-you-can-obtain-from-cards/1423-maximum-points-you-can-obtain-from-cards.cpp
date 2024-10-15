class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0;
        int rsum = 0;
        int maxSum = 0;
        int n = cardPoints.size();
        for(int i = 0; i<k; i++){
            lsum+=cardPoints[i];
            maxSum = lsum;
        }
        int rightInd = n-1;
        for(int i = k-1; i>=0; i--){
            lsum-=cardPoints[i];
            rsum+=cardPoints[rightInd];
            maxSum = max(maxSum, lsum+rsum);
            rightInd--;
        }

        return maxSum;
        
    }
};