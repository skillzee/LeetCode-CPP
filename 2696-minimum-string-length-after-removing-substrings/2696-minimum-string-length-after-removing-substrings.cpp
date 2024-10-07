class Solution {
public:
    int minLength(string s) {
        int n = s.size();
        
        for (int i = 1; i < s.size(); ++i) {
            if (i > 0 && s[i - 1] == 'A' && s[i] == 'B') {
                s.erase(i - 1, 2); 
                i -= 2; 
            } 
            else if (i > 0 && s[i - 1] == 'C' && s[i] == 'D') {
                s.erase(i - 1, 2);  
                i -= 2;  
            }
        }

        return s.size(); 
    }
};
