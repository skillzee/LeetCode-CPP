class Solution {
public:

    static bool comp(pair<string,int> a, pair<string,int> b){
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return b.second < a.second;
    }

    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        map<string, int> freq;
        for(auto word: words){
            freq[word]++;
        }
        vector<pair<string, int>> v;
        for(auto it: freq){
            v.push_back({it.first, it.second});
        }

        sort(v.begin(), v.end(), comp);

        for(int i = 0; i<k; i++){
            ans.push_back(v[i].first);
        }
        return ans;
    }
};