class Solution {
public:

    bool isVowel(char ch) {
        ch = tolower(ch); 
        return(ch=='a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    
    }



    int maxVowels(string s, int k) {
        int n = s.length();

        int l = 0;
        int r = 0;
        int ans = INT_MIN;
        int curr = 0;

        while(r<n){

            while(r-l+1<=k and r<n){
                if(isVowel(s[r])){
                    curr++;
                }

                r++;
            }

            ans = max(ans, curr);

            if(isVowel(s[l])){
                curr--;
            }

            l++;
        }


        return ans;
    }
};