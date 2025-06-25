class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp; // currSum -> index;
        int currSum = 0;
        int ans = 0;
        mp[currSum] = -1;
        for(int i = 0; i<n; i++){
            if(nums[i] == 0){
                currSum += -1;
            }else{
                currSum+=1;
            }

            if(mp.find(currSum) != mp.end()){
                int len = i-mp[currSum];
                ans = max(len, ans);
            }else{
                mp[currSum] = i;
            }
            
            
        }

        return ans;
    }
};