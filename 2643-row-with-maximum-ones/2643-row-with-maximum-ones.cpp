class Solution {
public:
    int firstOccur(vector<int> arr, int n, int target){
        int low = 0;
        int high = n-1;
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(arr[mid]>=target){
                high = mid-1;
                ans = mid;
            }else{
                low = mid+1;
            }
        }
        if(ans == -1) return n;
        return ans;
    }

    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int index = -1;
        int currOnes = -1;
        for(int i = 0; i<n; i++){
            sort(mat[i].begin(), mat[i].end());
            int m = mat[i].size();
            int ones = m - firstOccur(mat[i], m, 1);
            if(ones>currOnes){
                currOnes = ones;
                index = i;
            }
        }

        return {index, currOnes};
    }
};