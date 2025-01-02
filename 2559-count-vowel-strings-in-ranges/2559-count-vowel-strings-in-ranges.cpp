class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> temp(words.size(), 0);
        for(int i = 0; i<words.size(); i++){
            string word = words[i];
            if(word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u'){
                if(word[word.length()-1] == 'a' || word[word.length()-1] == 'e' || word[word.length()-1] == 'i' || word[word.length()-1] == 'o' || word[word.length()-1] == 'u'){
                    temp[i] = 1;
                }
            }
        }
        vector<int> ans;
        for(int i = 0; i<queries.size(); i++){
            int start = queries[i][0];
            int end = queries[i][1];
            int cnt = 0;
            for(int i = start; i<=end; i++){
                if(temp[i] == 1){
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};