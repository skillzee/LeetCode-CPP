class Solution {
public:

    int countSubsets(int idx, int currOr, vector<int> &nums, int maxOr){

        if(idx>=nums.size()){
            if(currOr == maxOr){
                return 1;
            }
            return 0;
        }

        // take
        int take = countSubsets(idx+1, currOr|nums[idx], nums, maxOr);

        // not take
        int notTake = countSubsets(idx+1, currOr, nums, maxOr);

        return take+notTake;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for(int &num: nums){
            maxOr |= num;
        }

        int currOr = 0;
        return countSubsets(0, currOr, nums, maxOr);
    }
};