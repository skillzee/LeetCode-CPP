class Solution {
public:
    void solve(string &str, int k, string &ans, int start) {
        if (k == 0 || start >= str.size()) return;
        
        // Find the smallest character that can be moved to 'start'
        int minPos = start;
        for (int i = start + 1; i < str.size() && i - start <= k; ++i) {
            if (str[i] < str[minPos]) {
                minPos = i;
            }
        }
        
        // If the minimum character is not at the current 'start', we perform swaps
        if (minPos != start) {
            // Perform swaps to move the smallest character to 'start'
            char minChar = str[minPos];
            for (int i = minPos; i > start; --i) {
                swap(str[i], str[i-1]);
            }
            
            // Reduce the swap count by how many swaps we performed
            k -= (minPos - start);
        }
        
        // Compare with the current best solution and update if the new one is smaller
        if (str.compare(ans) < 0) {
            ans = str;
        }
        
        // Recurse for the next position
        solve(str, k, ans, start + 1);
    }

    string minInteger(string num, int k) {
        string ans = num;
        solve(num, k, ans, 0);
        return ans;
    }
};
