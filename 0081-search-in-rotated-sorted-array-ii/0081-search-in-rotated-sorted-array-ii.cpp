class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int n = arr.size();
        if(arr[0] == target) return true;
        if(arr[n-1] == target) return true;
        int low = 1;
        int high = n-2;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(arr[mid] == target){
                return true;
            }
            if (arr[mid] == arr[low] && arr[mid] == arr[high]){
                high--;
                low++;
            }
            else if(arr[mid]>=arr[low]){
                if(arr[low]<=target and arr[mid]>target){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }else{
                if(arr[high]>=target and arr[mid]<target){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }

        }

        return false;
    }
};