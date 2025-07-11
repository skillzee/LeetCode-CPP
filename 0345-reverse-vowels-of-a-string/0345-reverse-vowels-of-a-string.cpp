class Solution {
public:
    bool isVowel(char c){
        if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            return true;
        }

        return false;
    }

    string reverseVowels(string s) {
        int n = s.length();
        string temp = s;
        int l = 0;
        int r = n-1;
        while(l<=r){
            while(l<r and !isVowel(s[l])){
                l++;
            }
            while(l<r and !isVowel(s[r])){
                r--;
            }
            swap(s[l], s[r]);
            l++;
            r--;
            
            
        }

        return s;
    }
};