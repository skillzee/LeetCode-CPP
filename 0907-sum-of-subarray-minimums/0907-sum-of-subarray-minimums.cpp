class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int MOD = 1e9+7;
        stack<int> st1;
        stack<int> st2;
        vector<int> left(n);
        vector<int> right(n);
        // For left
        for(int i = 0; i<n; i++){
            while(!st1.empty() and arr[st1.top()]>arr[i]){
                st1.pop();
            }
            left[i] = st1.empty()?i+1:i-st1.top();
            st1.push(i);

        }

        // For Right
        for(int i = n-1; i>=0; i--){
            while(!st2.empty() and arr[st2.top()]>=arr[i]){
                st2.pop();
            }

            right[i] = st2.empty() ? n-i : st2.top()-i;
            st2.push(i);
        }

        long long ans = 0;
        for(int i = 0; i<n; i++){
            ans+=(long long)left[i]*right[i]*arr[i];
        }

        return ans%MOD;
    }
};