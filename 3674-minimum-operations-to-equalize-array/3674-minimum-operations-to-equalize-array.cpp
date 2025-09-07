class Solution {
public:
    int minOperations(vector<int>& nums) {
        int num = nums[0];
        for(auto it: nums){
            if(it!=num){
                return 1;
            }
        }

        return 0;
    }
};