class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.length();
        map<char, int> mp;
        for(auto it: word){
            mp[it]++;
        }
        int ans = 1; 
        for(auto it: mp){
            if(it.second>1){
                ans+=it.second-1;
            }
        }

        return ans;
    }
};