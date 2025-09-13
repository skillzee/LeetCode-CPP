class Solution {
public:

    bool isVowel(char ch){
        set<char> st = {'a', 'e', 'i', 'o', 'u'};
        if(st.count(ch)){
            return true;
        }
        return false;
    }


    int maxFreqSum(string s) {
        unordered_map<char, int> vowels;
        unordered_map<char, int> consonants;


        for(auto it: s){
            if(isVowel(it)){
                vowels[it]++;
            }else{
                consonants[it]++;
            }
        }

        int maxVowel = 0;
        int maxConsonants = 0;

        for(auto it: vowels){
            maxVowel = max(maxVowel, it.second);
        }
        for(auto it: consonants){
            maxConsonants = max(maxConsonants, it.second);
        }


        return maxConsonants+maxVowel;
    }
};