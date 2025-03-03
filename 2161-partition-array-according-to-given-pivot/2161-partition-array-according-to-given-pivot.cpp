class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> small, equal, big;

        for(auto it: nums){
            if(it<pivot) small.push_back(it);
            if(it == pivot) equal.push_back(it);
            if(it>pivot) big.push_back(it);
        }
        vector<int> ans;
        for(auto it: small){
            ans.push_back(it);
        }
        for(auto it: equal){
            ans.push_back(it);
        }
        for(auto it: big){
            ans.push_back(it);
        }

        return ans;

    }
};