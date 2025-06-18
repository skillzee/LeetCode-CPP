class Solution {
public:
    void helper(string digits, int idx, string comb, vector<string> &ans, map<char, string> &mp){
        if(idx == digits.length()){
            ans.push_back(comb);
            return;
        }

        string letters = mp.at(digits[idx]);
        for(char letter: letters){
            helper(digits, idx+1, comb+letter, ans, mp);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()) return ans;

        map<char, string> mp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        helper(digits, 0, "", ans, mp);
        return ans;
    }
};