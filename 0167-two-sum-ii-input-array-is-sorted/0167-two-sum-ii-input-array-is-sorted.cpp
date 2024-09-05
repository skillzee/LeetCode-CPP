class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        vector<int> ans;
    unordered_map<int, int> mp;

    for(int i = 0; i < v.size(); i++)
    {

        int comp = target - v[i];
        if(mp.find(comp)!=mp.end()){
            ans.push_back(mp[comp]+1);
            ans.push_back(i+1);
        }
        mp[v[i]] = i;
    }

    return ans;
    }
};