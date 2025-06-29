class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        int n = arr.size();
        int first = -1; 
        int last = -1;
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(arr[mid] == target){
                first = mid;
                high = mid-1;
            }
            else if(target>arr[mid]){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }


        low = 0; high = n-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(arr[mid] == target){
                last = mid;
                low = mid+1;
            }
            else if(target>arr[mid]){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }

        return {first, last};

    }
};