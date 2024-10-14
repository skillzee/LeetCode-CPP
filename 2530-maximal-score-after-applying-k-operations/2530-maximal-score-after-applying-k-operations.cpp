class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long res = 0;

        priority_queue<int> pq(nums.begin(), nums.end());//max Heap

        while(k--){
            int maxEle = pq.top();
            pq.pop();
            res+=maxEle;
            maxEle = ceil(maxEle/3.0);
            pq.push(maxEle);
        }

        return res;

    }
};