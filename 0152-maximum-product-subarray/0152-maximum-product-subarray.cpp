class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;
        int n = nums.size();
        int prod = 1;
        for(int i = 0; i<n; i++){
            prod*=nums[i];
            res = max(res, prod);
        }
        if(res==1){
            return 0;
        }
        return res;
        
    }
};