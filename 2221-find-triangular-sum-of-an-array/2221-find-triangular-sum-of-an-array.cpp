class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        while(n!=1){
            vector<int> temp;
            for(int i = 0; i<n-1; i++){
                int one = nums[i];
                int two = nums[i+1];
                temp.push_back((one+two)%10);
                
            }
            nums= temp;

            n--;
        }

        return nums[0];


        
    }
};