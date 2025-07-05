class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        map<int, int> mp;
        for(auto it: arr){
            mp[it]++;
        }
        int ans = INT_MIN;

        for(auto it: mp){
            if(it.first == it.second){
                ans = max(ans, it.first);
            }
        }

        if(ans == INT_MIN) return -1;

        return ans;
    }
};