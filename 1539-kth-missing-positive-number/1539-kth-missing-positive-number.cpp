class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int highest = *max_element(arr.begin(), arr.end());
        vector<bool> present(highest+k+1, false);
        for(auto it: arr){
            present[it] = true;
        }
        int ans = 0;
        // cout<<"Limit"<<present.size()<<endl;
        int temp = k;
        for(int i =1; i<=highest+k+1; i++){
            if(!present[i]){
                temp-=1;
                // cout<<k<<" ";
            }
            // cout<<"i->"<<i<<endl;
            if(temp == 0){
                return i;
            }
        }

        return -1;

    }
};