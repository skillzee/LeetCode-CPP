class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid] == target){
                return mid;
            }else if((mid == n-1 and nums[mid]<target) or ( nums[mid]<target and nums[mid+1]>target)){
                return mid+1;
            }else if((mid == 0 and nums[mid]>target) or ( nums[mid]>target and nums[mid+1]<target)){
                return mid-1;
            }
            else if(nums[mid] >target){
                high = mid-1;
            }else{
                low = mid+1;
            }

        }

        return -1;

    }
};