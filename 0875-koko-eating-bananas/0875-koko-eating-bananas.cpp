class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxElement = *max_element(piles.begin(), piles.end());
        int low = 1;
        int high = maxElement;
        int ans = INT_MAX;
        while(low<=high){
            int mid = low+(high-low)/2;
            long long sum = 0;
            for(auto it: piles){
                sum+= (it+mid-1)/mid;
            }
            if(sum<=h){
                ans = min(ans, mid);
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        return ans;
    }
};