class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffixProd(n, 1);
        vector<int> prefixProd(n, 1);
        suffixProd[n-1] = nums[n-1];
        vector<int> res(n);
        for(int i = n-2; i>=0; i--){
            suffixProd[i] = suffixProd[i+1]*nums[i];
        }
        int curr = 1;
        for(int i = 0; i<n; i++){
            curr*=nums[i];
            prefixProd[i] = curr;
            if(i == 0 || i == n-1){
                if(i == 0) res[i] = suffixProd[i+1];
                if(i == n-1) res[i] = prefixProd[i-1];
            }else{
            res[i] = prefixProd[i-1] * suffixProd[i+1];
            }
        }

        return res;
    }
};