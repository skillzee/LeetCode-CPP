class Solution {
public:
    char solve(string s, int k){
        if(s.length()>k){
            return s[k-1];
        }

        string temp = "";
        for(int i = 0; i<s.length(); i++){
            temp+= char(s[i] + 1);
        }

        return solve(s+temp, k);
    }

    char kthCharacter(int k) {
        string s = "a";
        return solve(s, k);
    }
};