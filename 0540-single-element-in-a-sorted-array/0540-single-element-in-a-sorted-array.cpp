class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low= 0;
        int high = n-1;
        if(n == 1) return nums[0];

        while(low<=high){
            int mid = low+(high-low)/2;

            if(mid == 0){
                if(nums[mid]!=nums[mid+1]){
                    return nums[mid];
                }else{
                    low = mid+1;
                }
            }else if(mid == n-1){
                if(nums[mid] != nums[mid-1]){
                    return nums[mid];
                }else{
                    high = mid-1;
                }
            }else if(nums[mid] != nums[mid-1] and nums[mid] != nums[mid+1]){
                return nums[mid];
            }else if(nums[mid] == nums[mid+1]){
                if(mid%2 == 0){
                    low = mid+2;
                }else{
                    high = mid-1;
                }
            }else if(nums[mid] == nums[mid-1]){
                if(mid%2 != 0){
                    low = mid+1;
                }else{
                    high = mid-2;
                }
            }

        }
        return 0;
    }
};