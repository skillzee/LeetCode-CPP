class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        reverse(s.begin(), s.end());
        string ans = "", temp = "";
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                temp +=s[i];
            }else if(!temp.empty()) {
                reverse(temp.begin(), temp.end());
                if (!ans.empty()) ans += " ";
                ans += temp;
                temp = "";
            }
        }
        if (!temp.empty()) {
            reverse(temp.begin(), temp.end());
            if (!ans.empty()) ans += " ";
            ans += temp;
        }
        return ans;
    }
};
