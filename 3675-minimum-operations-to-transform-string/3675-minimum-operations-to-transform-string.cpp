class Solution {
public:
    int minOperations(string s) {
        int steps = 0;
        int n = s.length();
        vector<int> occurences(26);

        for(int i = 0; i<n; i++){
            char ch = s[i];
            occurences[ch-'a']++;
        }


        for(int i = 1; i<26;i++){
            if(occurences[i]!=0){
                occurences[(i+1)%26]+=occurences[i];
                occurences[i] = 0;
                steps++;
            }
        }

        // if(steps == 0) return 0;
        return steps;
    }
};