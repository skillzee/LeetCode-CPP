class Solution {
public:
    // int findSmall(vector<int> &arr){
    //     int smallest = INT_MAX;
    //     for(int i = 1; i<arr.size(); i++){
    //         if(arr[i]<smallest){
    //             smallest = arr[i];
    //         }
    //     }
    //     return smallest;
    // }

    // int findIndex(int element, vector<int> &arr){
    //     for(int i =0; i<arr.size(); i++){
    //         if(arr[i] == element){
    //             return i;
    //         }
    //     }
    //     return  0;
    // }

    // vector<int> arrayRankTransform(vector<int>& arr) {
    //     int size = arr.size();
    //     vector<int> temp(size), temp2(size);
    //     int rank = 0;
    //     temp2.assign(arr.begin(), arr.end());
    //     sort(temp2.begin(), temp2.end());
    //     for(int i = 0; i<size; i++){
    //         if(temp2[i]!=temp2[i+1]){
    //             rank++;
    //         }
    //         int index = findIndex(temp2[i], arr);
    //         temp[index] = rank;
    //     }

    //     return temp;
    // }

    vector<int> arrayRankTransform(vector<int>& arr) {

        if(arr.empty())
            return arr;

        vector<int> v = arr;
        sort(v.begin(), v.end());

        map<int,int> mp;

        int rank = 1;

        for(int i = 0; i<v.size()-1; i++){
            mp[v[i]] = rank;
            if(v[i] != v[i+1])
                rank++;
        }
        mp[v[v.size()-1]] = rank;

        for(int i = 0; i<arr.size(); i++){

            v[i] = mp[arr[i]];

        }

        return v;
    }



};