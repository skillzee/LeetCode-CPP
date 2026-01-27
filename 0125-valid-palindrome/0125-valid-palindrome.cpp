class Solution {
public:
    bool isPal(string s){
        string temp = s;

        reverse(s.begin(), s.end());

        if(s == temp) return true;

        return false;
    }

    bool isPalindrome(string s) {
        string finalStr = "";

        for(auto it: s){
            if(it>=65 and it<=90){
                finalStr+=tolower(it);
            }
            else if(it>=97 and it<=122){
                finalStr+=tolower(it);
            }else if(it>='0' and it<='9'){
                finalStr+=(it);
            }
        }


        if(isPal(finalStr)) return true;

        return false;
    }
};