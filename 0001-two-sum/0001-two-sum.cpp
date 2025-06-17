class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
    vector<int> ans;
    unordered_map<int, int> mp;

    for(int i = 0; i < v.size(); i++)
    {
        // int complement = target - v[i];
        // if(mp.find(complement) != mp.end())
        // {
        //     ans.push_back(mp[complement]);
        //     ans.push_back(i);
        //     return ans;
        // }
        // mp[v[i]] = i;

        int comp = target - v[i];
        if(mp.find(comp)!=mp.end()){
            ans.push_back(mp[comp]);
            ans.push_back(i);
        }
        mp[v[i]] = i;
    }

    return ans;
    }
};