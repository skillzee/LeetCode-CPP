class Solution {
public:
    string intToRoman(int num) {
        vector<int> val = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> symb = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string ans = "";
        for(int i = 0; i<val.size(); i++){
            while(num>=val[i]){
                ans+=symb[i];
                num-=val[i];
            }
        }
        return ans;
    }
};