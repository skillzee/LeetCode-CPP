class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> count(121, 0);
        for (auto it : ages) {
            count[it]++;
        }
        int ans = 0;
        for (int i = 1; i < 121; i++) {
            if (count[i] == 0)
                continue;
            for (int j = 1; j < 121; j++) {

                if (count[j] == 0)
                    continue;
                if (j <= 0.5 * i + 7 || j > i || (j > 100 && i < 100))
                    continue;
                ans += count[i] * count[j];
                if(i == j) ans-=count[i];
            }
        }
        return ans;
    }
};