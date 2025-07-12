class Solution {
public:
    string reverseWords(string s){
        reverse(s.begin(), s.end());
        
        int i =0;

        // ye l aur r particular words ko reverse krenge
        int l = 0;
        int r = 0;


        int n = s.length();
        while(i<n){
            while(i<n and s[i] != ' '){
                s[r] = s[i];
                i++;
                r++;
            }

            if(l<r){
                reverse(s.begin()+l, s.begin()+r);

                s[r] = ' ';
                r++;
                l = r;
            }

            i++; // this will alsways badhta rahega.
        }

        s = s.substr(0, r-1);


        return s;
    }
};