class Solution {
public:
    bool allZeroes(vector<int> arr){
        for(int &i: arr){
            if(i!=0) return false;
        }

        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        int i = 0;
        int j = 0;
        int n = s.size();
        int k = p.size();

        vector<int> occurence(26);
        for(int i = 0; i<k; i++){
            char ch = p[i];
            occurence[ch-'a']++;
        }

        vector<int> res;

        while(j<n){
            occurence[s[j]-'a']--;

            if(j-i+1 ==k){
                if(allZeroes(occurence)){
                    res.push_back(i);
                }
                occurence[s[i]-'a']++;
                i++;
            }
            j++;
        }

        return res;
    }
};