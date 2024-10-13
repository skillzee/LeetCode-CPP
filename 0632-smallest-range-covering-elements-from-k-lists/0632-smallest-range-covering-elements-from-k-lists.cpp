class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();

        vector<int> vec(k, 0);
        vector<int> res = {-1000000, 1000000};

        while (true) {
            int minEle = INT_MAX;
            int maxEle = INT_MIN;
            int minEleListIndex = 0;

            for (int i = 0; i < k; i++) {
                int listIdx = i;
                int eleIdx = vec[i];
                int element = nums[listIdx][eleIdx];

                if (element < minEle) {
                    minEle = element;
                    minEleListIndex = listIdx;
                }
                maxEle = max(maxEle, element);
            }

            if (maxEle - minEle < res[1] - res[0]) {
                res[0] = minEle;
                res[1] = maxEle;
            }

            int nextIdx = vec[minEleListIndex] + 1;
            if (nextIdx >= nums[minEleListIndex].size()) {
                break;
            }
            vec[minEleListIndex] = nextIdx;
        }
        return res;
    }
};