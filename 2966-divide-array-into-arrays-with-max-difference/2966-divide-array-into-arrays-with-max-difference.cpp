class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int i = 0; i<n; i+=3){
            int one = nums[i];
            int two = nums[i+1];
            int three = nums[i+2];

            if(three - one <=k){
                ans.push_back({one, two, three});
            }else{
                return {};
            }
        }
        
        return ans;
        
        
    }
};