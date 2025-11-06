class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int maxLen = 0;

        for(int i = 1; i<n-1; i++){
            if(arr[i-1]<arr[i] and arr[i]>arr[i+1]){
                int left = i-1;
                int right = i+1;

                // left
                while(left>0 and arr[left-1]<arr[left]){
                    left--;
                }

                // right
                while(right<n-1 and arr[right+1]<arr[right]){
                    right++;
                }


                int currLen = right-left+1;
                maxLen = max(maxLen, currLen);

                i = right;
            
            }
        }

        return maxLen;
    }
};