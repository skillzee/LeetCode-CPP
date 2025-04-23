class Solution {
public:
    int findGroup(int num){
        int temp = 0;
        while(num>0){
            temp+=num%10;
            num/=10;
        }

        return temp;
    }

    int countLargestGroup(int n) {
        unordered_map<int, vector<int>> mp;
        for(int i = 1; i<=n; i++){
            int group = findGroup(i);
            mp[group].push_back(i);
        }

        int maxSize = 0;
        for(auto it: mp){
            int size = it.second.size();
            maxSize = max(size, maxSize);
        }

        int ans = 0;
        for(auto it: mp){
            if(it.second.size() == maxSize) ans++;
        }

        return ans;

        

    }
};