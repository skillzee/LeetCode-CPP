class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        if(n == k) return "0";
        string result = "";//This wil act as a stack
        for(int i = 0; i<n; i++){
            while(result.length()>0 and result.back()>num[i] and k>0){
                result.pop_back();
                k--;
            }

            if(result.length()>0 || num[i] != '0'){
                result.push_back(num[i]); // to avoid leading zeroes
            }
        }

        while(result.length()>0 and k>0){
            result.pop_back();
            k--;
        }

        if(result == "") return "0";

        return result;


    }
};