class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();
        if(n == 1){
            return 0;
        }
        if(n == 2) return arr[0] > arr[1] ? 0 : 1;
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(( mid == 0 || arr[mid]>arr[mid-1]) and (mid == n-1 || arr[mid]>arr[mid+1])){
                return mid;
            }
            else if(mid<n-1 and arr[mid]<arr[mid+1]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

        return -1;

    }
};