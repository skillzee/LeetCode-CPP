class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string, int> mp;


        for(auto it: arr1){
            string num = to_string(it);
            string prefix = "";
            for(auto ch: num){
                prefix+=ch;
                mp[prefix]++;
            }
        }


        int maxAnswer = 0;
        for(auto it: arr2){
            string num = to_string(it);
            string prefix = "";
            for(auto ch:num){
                prefix+=ch;
                if(mp.find(prefix)!=mp.end()){
                    maxAnswer = max(maxAnswer, static_cast<int>(prefix.length()));
                }
            }
        }
        return maxAnswer;
    }
};