class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> res;
        int maxi = *max_element(candies.begin(), candies.end());
        for(auto it: candies){
            if(it+extraCandies >= maxi){
                res.push_back(true);
            }else{
                res.push_back(false);
            }
        }

        return res;
        




    }
};