class Solution {
public:
    void sortColors(vector<int>& arr) {
    int n = arr.size();
    int left = 0;
    int mid = 0;
    int right = n-1;

    while(right>mid){
        if(arr[mid] == 1){
            mid++;
        }
        if(arr[mid] == 2){
            swap(arr[mid], arr[right]);
            right--;
        }
        if(arr[mid] == 0){
            swap(arr[mid], arr[left]);
            mid++; 
            left++;
        }
    }


    }
};