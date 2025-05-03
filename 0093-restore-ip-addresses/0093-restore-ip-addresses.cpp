class Solution {
public:
    int n;
    vector<string> result;

    bool isValid(string str){
        if(str[0] == '0') return false;

        int val = stoi(str);

        if(val>255) return false;

        return true;
    }

    void solve(string &s, int ind, int parts, string curr){
        if(ind == n and parts == 4){
            curr.pop_back();
            result.push_back(curr);
            return;
        }
        if(ind+1<=n){
        solve(s, ind+1, parts+1, curr+s.substr(ind, 1)+".");
        }
        if(ind+2<=n and isValid(s.substr(ind,2))){
        solve(s, ind+2, parts+1, curr+s.substr(ind, 2)+".");
        }
        if(ind+3<=n and isValid(s.substr(ind,3))){
        solve(s, ind+3, parts+1, curr+s.substr(ind, 3)+".");
    }
    }

    vector<string> restoreIpAddresses(string s) {
        n = s.length();
        result.clear();
        if(n>12){
            return {};
        }

        int parts = 0;
        string curr = "";
        solve(s, 0, parts, curr);

        return result;
    }
};