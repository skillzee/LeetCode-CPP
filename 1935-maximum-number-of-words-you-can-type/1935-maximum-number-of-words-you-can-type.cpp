class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<int> broken(26, 0);
        for(auto it: brokenLetters){
            broken[it-'a'] = 1;
        }
        int count = 0;
        bool ok = true;
        for (int i = 0; i <= text.size(); i++) {
            if (i == text.size() || text[i] == ' ') {
                if (ok) count++;
                ok = true;
            } else if (broken[text[i] - 'a']) {
                ok = false;
            }
        }
        return count;


    }
};