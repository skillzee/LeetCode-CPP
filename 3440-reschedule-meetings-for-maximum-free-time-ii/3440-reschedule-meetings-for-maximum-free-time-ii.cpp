class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> freeArray; //Strore duration of free gaps
        freeArray.push_back(startTime[0] - 0);
        for(int i =1; i<n; i++){ 
            freeArray.push_back(startTime[i] - endTime[i-1]);
        }

        freeArray.push_back(eventTime- endTime[n-1]); 

        int m = freeArray.size();

        vector<int> maxRightFree(m ,0);
        vector<int> maxLeftFree(m ,0);

        for(int i = m-2; i>=0; i--){
            maxRightFree[i] = max(maxRightFree[i+1], freeArray[i+1]);
        }

        for(int i = 1; i<m; i++){
            maxLeftFree[i] = max(maxLeftFree[i-1], freeArray[i-1]);
        }


        int result = 0;

        for(int i = 1; i<m; i++){
            int currEventTime = endTime[i-1]-startTime[i-1]; // Duration of event = d


            // Case1 --> Moving completely out
            if(currEventTime <= max(maxLeftFree[i-1], maxRightFree[i])){
                result = max(result, freeArray[i-1]+currEventTime+freeArray[i]);
            }

            // Case 2--> Shift Left or right

            result = max(result, freeArray[i-1]+freeArray[i]);

        }

        return result;


    }
};