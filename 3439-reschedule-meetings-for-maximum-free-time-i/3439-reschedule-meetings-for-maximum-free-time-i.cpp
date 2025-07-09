class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> freeArray; //Strore duration of free gaps
        freeArray.push_back(startTime[0] - 0);
        for(int i =1; i<n; i++){ 
            freeArray.push_back(startTime[i] - endTime[i-1]);
        }

        freeArray.push_back(eventTime- endTime[n-1]); 

        // Sliding window

        int i =0; 
        int j = 0;
        int maxSum = INT_MIN;
        int currSum = 0;
        int m = freeArray.size();
        while(j<m){
            currSum += freeArray[j];

            while(i<m and j-i+1 > k+1){
                currSum-=freeArray[i];
                i++;
            }

            maxSum = max(maxSum, currSum);
            j++;
        }

        return maxSum;



    }
};